#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "../../include/kernel/kheap.h"
#include "../../include/kernel/paging.h"
#include "../../../libc/include/stdio.h"
#include "../../include/kernel/irq.h"

#define INDEX_FROM_BIT(a) (a/32)
#define OFFSET_FROM_BIT(a) (a%32)

uint32_t *frames;
uint32_t nframes;

extern uint32_t placement_address;

page_directory_t *kernel_directory = 0;
page_directory_t *current_directory = 0;

static void set_frame(uint32_t frame_addr)
{
    uint32_t frame = frame_addr/0x1000;
    uint32_t index = INDEX_FROM_BIT(frame);
    uint32_t offset = OFFSET_FROM_BIT(frame);
    frames[index] |= (1<<offset);
}

static void clear_frame(uint32_t frame_addr)
{
    uint32_t frame = frame_addr/0x1000;
    uint32_t index = INDEX_FROM_BIT(frame);
    uint32_t offset = OFFSET_FROM_BIT(frame);
    frames[index] &= ~(1<<offset);
}

static uint32_t check_frame(uint32_t frame_addr)
{
    uint32_t frame = frame_addr/0x1000;
    uint32_t index = INDEX_FROM_BIT(frame);
    uint32_t offset = OFFSET_FROM_BIT(frame);
    return (frames[index] & (1<<offset));
}

static uint32_t first_free_frame()
{
    for(uint32_t i = 0; i < INDEX_FROM_BIT(nframes); i++)
    {
        if(frames[i] != 0xFFFFFFFF)
        {
            for(uint32_t j = 0; j<32; j++)
            {
                if(!(frames[i] & ((1<<j))))
                    return 32*i + j;
            }
        }
    }
}

void alloc_frame(page_t *page, int is_kernel, int is_writeable)
{
    // frame already allocated to page
    if(page->frame != 0)
        return;
    else
    {
        uint32_t index = first_free_frame();
        if(index == (uint32_t) - 1)
        {
            printf("No free frames\n");
            while(1);
        }

        set_frame(index*0x1000);
        page->present = 1;
        page->rw = is_writeable?1:0;
        page->user = is_kernel?0:1;
        page->frame = index;           
    }
}

void free_frame(page_t *page)
{
    uint32_t frame = page->frame;

    //page did not have a frame allocated
    if(!frame)
        return;
    else
    {
        clear_frame(frame);
        page->frame = 0;
    }
}

void init_paging()
{
    uint32_t mem_end_page = 0x1000000;
    nframes = mem_end_page/0x1000;

    frames = (uint32_t *)kmalloc(INDEX_FROM_BIT(nframes), 0, 0);
    memset(frames, 0, INDEX_FROM_BIT(nframes));
    
    kernel_directory = (page_directory_t *)kmalloc(sizeof(page_directory_t),1,0);
    memset(kernel_directory, 0, sizeof(page_directory_t));
    current_directory = kernel_directory;

    uint32_t i=0x00;
    while(i<placement_address)
    { 
        alloc_frame(get_page(i, 1, kernel_directory), 0, 0);
        i+=0x1000;
    }

    //register_handler(14, &page_fault);

    switch_page_dir(kernel_directory);    
}

void switch_page_dir(page_directory_t *dir)
{
    current_directory = dir;
    asm volatile("mov %0, %%cr3":: "r"(&dir->tablesPhy));
    uint32_t cr0;
    asm volatile("mov %%cr0, %0": "=r"(cr0));
    cr0 |= 0x80000000; // Enable paging!
    asm volatile("mov %0, %%cr0":: "r"(cr0));
}

page_t *get_page(uint32_t address, int make, page_directory_t *dir)
{
    address /= 0x1000;
    uint32_t table_index = address/1024;

    if(dir->tables[table_index])
        return &dir->tables[table_index]->pages[address%1024];
    else if(make)
    {
        uint32_t temp;
        dir->tables[table_index] = (page_table_t *)kmalloc(sizeof(page_table_t), 1, &temp);
        memset(dir->tables[table_index], 0, 0x1000);
        dir->tablesPhy[table_index] = temp|0x07;
        return &dir->tables[table_index]->pages[address%1024];
    }
    else
        return 0;
}
