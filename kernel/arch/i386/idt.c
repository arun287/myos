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

    idt_insert(0, (uint32_t)irq0, 0x08, 0x8E);
    idt_insert(1, (uint32_t)irq1, 0x08, 0x8E);
    idt_insert(2, (uint32_t)irq2, 0x08, 0x8E);
    idt_insert(3, (uint32_t)irq3, 0x08, 0x8E);
    idt_insert(4, (uint32_t)irq4, 0x08, 0x8E);
    idt_insert(5, (uint32_t)irq5, 0x08, 0x8E);
    idt_insert(6, (uint32_t)irq6, 0x08, 0x8E);
    idt_insert(7, (uint32_t)irq7, 0x08, 0x8E);
    idt_insert(8, (uint32_t)irq8, 0x08, 0x8E);
    idt_insert(9, (uint32_t)irq9, 0x08, 0x8E);
    idt_insert(10, (uint32_t)irq10, 0x08, 0x8E);
    idt_insert(11, (uint32_t)irq11, 0x08, 0x8E);
    idt_insert(12, (uint32_t)irq12, 0x08, 0x8E);
    idt_insert(13, (uint32_t)irq13, 0x08, 0x8E);
    idt_insert(14, (uint32_t)irq14, 0x08, 0x8E);
    idt_insert(15, (uint32_t)irq15, 0x08, 0x8E);
    idt_insert(16, (uint32_t)irq16, 0x08, 0x8E);
    idt_insert(17, (uint32_t)irq17, 0x08, 0x8E);
    idt_insert(18, (uint32_t)irq18, 0x08, 0x8E);
    idt_insert(19, (uint32_t)irq19, 0x08, 0x8E);
    idt_insert(20, (uint32_t)irq20, 0x08, 0x8E);
    idt_insert(21, (uint32_t)irq21, 0x08, 0x8E);
    idt_insert(22, (uint32_t)irq22, 0x08, 0x8E);
    idt_insert(23, (uint32_t)irq23, 0x08, 0x8E);
    idt_insert(24, (uint32_t)irq24, 0x08, 0x8E);
    idt_insert(25, (uint32_t)irq25, 0x08, 0x8E);
    idt_insert(26, (uint32_t)irq26, 0x08, 0x8E);
    idt_insert(27, (uint32_t)irq27, 0x08, 0x8E);
    idt_insert(28, (uint32_t)irq28, 0x08, 0x8E);
    idt_insert(29, (uint32_t)irq29, 0x08, 0x8E);
    idt_insert(30, (uint32_t)irq30, 0x08, 0x8E);
    idt_insert(31, (uint32_t)irq31, 0x08, 0x8E);

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
