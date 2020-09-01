#include "../../include/kernel/kheap.h"
#include "../../include/kernel/vmm.h"
#include "../../../libc/include/stdio.h"
#include "../../include/kernel/irq.h"
#include "../../include/kernel/pmm.h"
#include "../../../libc/include/string.h"

extern uint32_t placement_address;

page_directory_t *kernel_directory = 0;
page_directory_t *current_directory = 0;

void init_vmm()
{
    kernel_directory = (page_directory_t *)kmalloc(sizeof(page_directory_t),1,0);
    memset(kernel_directory, 0, sizeof(page_directory_t));
    current_directory = kernel_directory;

    uint32_t i=0x00000000;
    while(i<placement_address)
    { 
        alloc_frame(get_page(i, 1, kernel_directory), 0, 0);
        i+=0x1000;
    }

    register_handler(IRQ_PAGE_FAULT, &page_fault);
    switch_page_dir(kernel_directory);    
}

void switch_page_dir(page_directory_t *dir)
{
    current_directory = dir;
    asm ("mov %0, %%cr3":: "r"(&dir->tablesPhy));
    uint32_t cr0;
    asm ("mov %%cr0, %0": "=r"(cr0));
    cr0 |= 0x80000000; // Enable paging!
    asm ("mov %0, %%cr0":: "r"(cr0));
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

void page_fault()
{
    uint32_t faulting_address;
    asm volatile("mov %%cr2, %0" : "=r" (faulting_address));

    printf("Page Fault - %x\n",faulting_address);

    while(1);
}
