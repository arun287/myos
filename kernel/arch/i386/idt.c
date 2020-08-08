#include "../../include/kernel/idt.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>

idt_entry_t idt_entries[256];
idt_ptr_t idt_ptr;

/* Initialises the first 32 Interrupts */
void init_idt()
{
    idt_ptr.limit = (sizeof(idt_entry_t)*256) - 1;
    idt_ptr.base = (uint32_t)&idt_entries;

    memset(&idt_entries, 0, sizeof(idt_entry_t)*256);

    idt_insert(0, (uint32_t)isr0, 0x08, 0x8E);
    idt_insert(1, (uint32_t)isr1, 0x08, 0x8E);
    idt_insert(2, (uint32_t)isr2, 0x08, 0x8E);
    idt_insert(3, (uint32_t)isr3, 0x08, 0x8E);
    idt_insert(4, (uint32_t)isr4, 0x08, 0x8E);
    idt_insert(5, (uint32_t)isr5, 0x08, 0x8E);
    idt_insert(6, (uint32_t)isr6, 0x08, 0x8E);
    idt_insert(7, (uint32_t)isr7, 0x08, 0x8E);
    idt_insert(8, (uint32_t)isr8, 0x08, 0x8E);
    idt_insert(9, (uint32_t)isr9, 0x08, 0x8E);
    idt_insert(10, (uint32_t)isr10, 0x08, 0x8E);
    idt_insert(11, (uint32_t)isr11, 0x08, 0x8E);
    idt_insert(12, (uint32_t)isr12, 0x08, 0x8E);
    idt_insert(13, (uint32_t)isr13, 0x08, 0x8E);
    idt_insert(14, (uint32_t)isr14, 0x08, 0x8E);
    idt_insert(15, (uint32_t)isr15, 0x08, 0x8E);
    idt_insert(16, (uint32_t)isr16, 0x08, 0x8E);
    idt_insert(17, (uint32_t)isr17, 0x08, 0x8E);
    idt_insert(18, (uint32_t)isr18, 0x08, 0x8E);
    idt_insert(19, (uint32_t)isr19, 0x08, 0x8E);
    idt_insert(20, (uint32_t)isr20, 0x08, 0x8E);
    idt_insert(21, (uint32_t)isr21, 0x08, 0x8E);
    idt_insert(22, (uint32_t)isr22, 0x08, 0x8E);
    idt_insert(23, (uint32_t)isr23, 0x08, 0x8E);
    idt_insert(24, (uint32_t)isr24, 0x08, 0x8E);
    idt_insert(25, (uint32_t)isr25, 0x08, 0x8E);
    idt_insert(26, (uint32_t)isr26, 0x08, 0x8E);
    idt_insert(27, (uint32_t)isr27, 0x08, 0x8E);
    idt_insert(28, (uint32_t)isr28, 0x08, 0x8E);
    idt_insert(29, (uint32_t)isr29, 0x08, 0x8E);
    idt_insert(30, (uint32_t)isr30, 0x08, 0x8E);
    idt_insert(31, (uint32_t)isr31, 0x08, 0x8E);

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
