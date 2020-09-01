#include "../../include/kernel/kheap.h"

extern uint32_t end;
uint32_t placement_address = (uint32_t)&end;

uint32_t kmalloc(uint32_t size, int align, uint32_t *phy)
{
    /***********************************************
     * All pages are 4096 bytes long (0x1000 bytes)
     * Thus the starting of a new page will have 0's 
     * in its first 12 bits (least signifigant). Thus
     * this code block checks if any of the first 12 
     * bits are set. If yes, then the page is aligned 
     * and added with 0x1000 to move to the next page
     ************************************************/
    if(align == 1 && (placement_address & 0x00000FFF))
    {
        placement_address &= 0xFFFFF000;
        placement_address += 0x1000;
    }

    if(phy)
        *phy = placement_address;

    uint32_t temp = placement_address;
    placement_address += size;

    return temp;
}
