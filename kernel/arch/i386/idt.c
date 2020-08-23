#include "../../../libc/include/libssp.h"
#include "../../../libc/include/stdlib.h"
#include "../../../libc/include/stdio.h"
#include "../../../libc/include/system.h"
#include "../../../libc/include/string.h"

#include "../../include/kernel/pic.h"
#include "../../include/kernel/idt.h"
#include "../../include/kernel/irq.h"

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
    outb(PIC_MASTER_DATA, 0x00);
    outb(PIC_SLAVE_DATA, 0x00);

    //Inserting CPU reserved interrupts and execptions into IDT
    idt_insert(IRQ_PAGE_FAULT, (uint32_t)isr_page_fault, 0x08, 0x8E);

    //Inserting Hardware Interrupt Servive Routines into IDT
    idt_insert(IRQ0, (uint32_t)isr0, 0x08, 0x8E);
    idt_insert(IRQ1, (uint32_t)isr1, 0x08, 0x8E);
    idt_insert(IRQ2, (uint32_t)isr2, 0x08, 0x8E);
    idt_insert(IRQ3, (uint32_t)isr3, 0x08, 0x8E);
    idt_insert(IRQ4, (uint32_t)isr4, 0x08, 0x8E);
    idt_insert(IRQ5, (uint32_t)isr5, 0x08, 0x8E);
    idt_insert(IRQ6, (uint32_t)isr6, 0x08, 0x8E);
    idt_insert(IRQ7, (uint32_t)isr7, 0x08, 0x8E);
    idt_insert(IRQ8, (uint32_t)isr8, 0x08, 0x8E);
    idt_insert(IRQ9, (uint32_t)isr9, 0x08, 0x8E);
    idt_insert(IRQ10, (uint32_t)isr10, 0x08, 0x8E);
    idt_insert(IRQ11, (uint32_t)isr11, 0x08, 0x8E);
    idt_insert(IRQ12, (uint32_t)isr12, 0x08, 0x8E);
    idt_insert(IRQ13, (uint32_t)isr13, 0x08, 0x8E);
    idt_insert(IRQ14, (uint32_t)isr14, 0x08, 0x8E);
    idt_insert(IRQ15, (uint32_t)isr15, 0x08, 0x8E);
    
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
