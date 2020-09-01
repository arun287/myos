#include "../../include/kernel/pmm.h"
#include "../../../libc/include/stdio.h"
#include "../../../libc/include/string.h"
#include "../../include/kernel/kheap.h"

extern uint32_t placement_address;

uint32_t *frames_bitmap;
uint32_t nframes;

void set_frame(uint32_t addr)
{
    uint32_t frame = addr/0x1000;
    frames_bitmap[WORD_OFFSET(frame)] |= (1<<BIT_OFFSET(frame));
}

void clear_frame(uint32_t addr)
{
    uint32_t frame = addr/0x1000;
    frames_bitmap[WORD_OFFSET(frame)] &= ~(1<<BIT_OFFSET(frame));
}

uint32_t check_frame(uint32_t addr)
{
    uint32_t frame = addr/0x1000;
    return (frames_bitmap[WORD_OFFSET(frame)] & (1<<BIT_OFFSET(frame)));
}

uint32_t first_free_frame()
{
    for(uint32_t i = 0; i < WORD_OFFSET(nframes); i++)
    {
        if(frames_bitmap[i] != 0xFFFFFFFF)
        {
            for(uint32_t j = 0; j<32; j++)
            {
                if(!(frames_bitmap[i] & ((1<<j))))
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

void init_pmm(uint32_t memSize)
{
    //Each frame is 4096 bits in size
    nframes = memSize/0x1000;
    
    //There are 4096 4KB frames in 16MB of memory
    frames_bitmap = (uint32_t *)kmalloc(WORD_OFFSET(nframes), 0, 0);
    memset(frames_bitmap, 0, WORD_OFFSET(nframes));
}
