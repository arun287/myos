#ifndef _KERNEL_GDT_H
#define _KERNEL_GDT_H

#include <stdlib.h>
#include <stdint.h>

typedef struct gdt_entry
{
    uint16_t limit_low;                 //lower 16 bits of limit
    uint16_t base_low;                  //lower 16 bits of base
    uint8_t base_mid;                   //middle 8 bits of base
    uint8_t base_high;                  //last 8 bits of base
    uint8_t access;                     //the access flag - contains information regarding Ring Level, Descriptor Type and Segment Type(Dat or Code)
    uint8_t granularity;                //the granularity flag - contains information regarding granularity and operand size
}gdt_entry_t;

typedef struct gdt_ptr
{
    uint16_t size;
    uint32_t offset;
}gdt_ptr_t;

extern void flush_gdt(uint32_t);        //function written in assembly
void init_gdt();
void gdt_insert(int32_t, uint32_t, uint32_t, uint8_t, uint8_t);

#endif
