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

extern void irq0();
extern void irq1();
extern void irq2();
extern void irq3();
extern void irq4();
extern void irq5();
extern void irq6();
extern void irq7();
extern void irq8();
extern void irq9();
extern void irq10();
extern void irq11();
extern void irq12();
extern void irq13();
extern void irq14();
extern void irq15();
extern void irq16();
extern void irq17();
extern void irq18();
extern void irq19();
extern void irq20();
extern void irq21();
extern void irq22();
extern void irq23();
extern void irq24();
extern void irq25();
extern void irq26();
extern void irq27();
extern void irq28();
extern void irq29();
extern void irq30();
extern void irq31();

extern void flush_idt(uint32_t);
void init_idt();
void idt_insert(uint8_t, uint32_t, uint16_t, uint8_t);

#endif
