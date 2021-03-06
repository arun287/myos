#ifndef _KERNEL_GDT_H
#define _KERNEL_GDT_H

#include <stdlib.h>
#include <stdint.h>

struct gdt_entry_struct
{
   uint16_t limit_low;           // The lower 16 bits of the limit.
   uint16_t base_low;            // The lower 16 bits of the base.
   uint8_t  base_mid;            // The mid 8 bits of the base.
   uint8_t  access;              // Access flags ----> Determines Ring Level
   uint8_t  granularity;         // Granularity ----> Determines Block Size
   uint8_t  base_high;           // The last 8 bits of the base.
} __attribute__((packed));
typedef struct gdt_entry_struct gdt_entry_t;

struct gdt_ptr_struct
{
   uint16_t limit;               // The upper 16 bits of all selector limits.
   uint32_t base;                // The address of the first gdt_entry_t struct.
} __attribute__((packed));
typedef struct gdt_ptr_struct gdt_ptr_t;

extern void flush_gdt(uint32_t);        //function written in assembly
void init_gdt();
void gdt_insert(int32_t, uint32_t, uint32_t, uint8_t, uint8_t);

#endif
