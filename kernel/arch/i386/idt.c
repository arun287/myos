#include "../../../libc/include/libssp.h"
#include "../../../libc/include/stdlib.h"
#include "../../../libc/include/stdio.h"
#include "../../../libc/include/system.h"
#include "../../../libc/include/string.h"

#include "../../include/kernel/pic.h"
#include "../../include/kernel/idt.h"

idt_entry_t idt_entries[256];
idt_ptr_t idt_ptr;

/* Initialises the first 32 Interrupts */
void init_idt()
{
    idt_ptr.limit = (sizeof(idt_entry_t)*256) - 1;
    idt_ptr.base = (uint32_t)&idt_entries;
 
    memset(&idt_entries, 0, sizeof(idt_entry_t)*256);

    //ICW1 is sent to indicate that ICW4 will follow
    outb(PIC_MASTER_COMMAND, ICW1);
    outb(PIC_SLAVE_COMMAND, ICW1);

    //Remapping IRQ's
    outb(PIC_MASTER_DATA, 0x20);
    outb(PIC_SLAVE_DATA, 0x28);

    //Enabling cascading of PIC's
    outb(PIC_MASTER_DATA, 0x04);
    outb(PIC_SLAVE_DATA, 0x02);

    //ICW4 is used for environment information
    outb(PIC_MASTER_DATA, ICW4);
    outb(PIC_SLAVE_DATA, ICW4);

    //Enable all IRQ's
    outb(PIC_MASTER_DATA, 0x0);
    outb(PIC_SLAVE_DATA, 0x0);

    //Inserting Interrupt Servive Routines into IDT
    idt_insert(32, (uint32_t)isr0, 0x08, 0x8E);
    idt_insert(33, (uint32_t)isr1, 0x08, 0x8E);
    idt_insert(34, (uint32_t)isr2, 0x08, 0x8E);
    idt_insert(35, (uint32_t)isr3, 0x08, 0x8E);
    idt_insert(36, (uint32_t)isr4, 0x08, 0x8E);
    idt_insert(37, (uint32_t)isr5, 0x08, 0x8E);
    idt_insert(38, (uint32_t)isr6, 0x08, 0x8E);
    idt_insert(39, (uint32_t)isr7, 0x08, 0x8E);
    idt_insert(40, (uint32_t)isr8, 0x08, 0x8E);
    idt_insert(41, (uint32_t)isr9, 0x08, 0x8E);
    idt_insert(42, (uint32_t)isr10, 0x08, 0x8E);
    idt_insert(43, (uint32_t)isr11, 0x08, 0x8E);
    idt_insert(44, (uint32_t)isr12, 0x08, 0x8E);
    idt_insert(45, (uint32_t)isr13, 0x08, 0x8E);
    idt_insert(46, (uint32_t)isr14, 0x08, 0x8E);
    idt_insert(47, (uint32_t)isr15, 0x08, 0x8E);
    
    flush_idt((uint32_t)&idt_ptr);
}

void idt_insert(uint8_t num, uint32_t base, uint16_t sel, uint8_t flag)
{
    idt_entries[num].base_low = base & 0xFFFF;
    idt_entries[num].base_high = (base >> 16) & 0xFFFF;

    idt_entries[num].sel = sel;
    idt_entries[num].always_zero = 0;
    idt_entries[num].flags = flag;
}
