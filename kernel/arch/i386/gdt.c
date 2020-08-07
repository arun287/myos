#include "../../include/kernel/gdt.h"
#include <stdint.h>
#include <stdio.h>

gdt_entry_t gdt_entries[5];
gdt_ptr_t gdt_ptr;

/* *******************************************************
 * This function initializes the GDT by defining the
 * Null Segment, Kernel Code Segment, Kernel Data Segment,
 * User Code Segment, and the User Data Segment
 *********************************************************/
void init_gdt()
{
    gdt_ptr.size = (sizeof(gdt_entry_t)*5) - 1;
    gdt_ptr.offset = (uint32_t)&gdt_entries[0];

    gdt_insert(0, 0, 0, 0, 0);                      //Null Segment
    gdt_insert(1, 0, 0xFFFFFFFF, 0x9A, 0xCF);       //Kernel Code Segment
    gdt_insert(2, 0, 0xFFFFFFFF, 0x92, 0xCF);       //Kernel Data Segment
    gdt_insert(3, 0, 0xFFFFFFFF, 0xFA, 0xCF);       //User Code Segment
    gdt_insert(4, 0, 0xFFFFFFFF, 0xF2, 0xCF);       //User Data Segment

    //asm volatile ("xchg %bx, %bx");
    //extern flush_gdt();
    printf("Inside init_gdt()\n");
    flush_gdt((uint32_t)&gdt_ptr);                  //loads the GDT pointer
    //__asm__("movl 4(%esp), %edx");
    //__asm__("lgdt (%edx)");
    //__asm__("movw $0x10,%ax");
    //__asm__("movw %ax, %ds");
    //__asm__("movw %ax, %es");

}

/* Function adds entries into the GDT */
void gdt_insert(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity)
{
    gdt_entries[num].access = access;
    gdt_entries[num].limit_low = limit & 0xFFFF;

    gdt_entries[num].granularity = (limit >> 16) & 0x0F;
    gdt_entries[num].granularity |= granularity & 0xF0;

    gdt_entries[num].base_low = base & 0xFFFF;
    gdt_entries[num].base_mid = (base >> 16) & 0xFF;
    gdt_entries[num].base_high = (base >> 24) & 0xFF;
}
