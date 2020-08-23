#ifndef _KERNEL_IDT_H
#define _KERNEL_IDT_H

#include <stdlib.h>
#include <stdint.h>

struct idt_entry_struct
{
   uint16_t base_low;             // The lower 16 bits of the address to jump to when this interrupt fires.
   uint16_t sel;                  // Kernel segment selector.
   uint8_t  always_zero;          // This must always be zero.
   uint8_t  flags;                // Specifies Privilege Level 
   uint16_t base_high;            // The upper 16 bits of the address to jump to.
} __attribute__((packed));
typedef struct idt_entry_struct idt_entry_t;

struct idt_ptr_struct
{
   uint16_t limit;
   uint32_t base;                // The address of the first element in our idt_entry_t array.
} __attribute__((packed));
typedef struct idt_ptr_struct idt_ptr_t;

extern void isr_page_fault();

extern void isr0();
extern void isr1();
extern void isr2();
extern void isr3();
extern void isr4();
extern void isr5();
extern void isr6();
extern void isr7();
extern void isr8();
extern void isr9();
extern void isr10();
extern void isr11();
extern void isr12();
extern void isr13();
extern void isr14();
extern void isr15();

extern void flush_idt(uint32_t);
void init_idt();
void idt_insert(uint8_t, uint32_t, uint16_t, uint8_t);

#endif
