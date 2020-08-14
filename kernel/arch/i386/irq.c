#include <stdint.h>

#include "../../../libc/include/libssp.h"
#include "../../../libc/include/stdlib.h"
#include "../../../libc/include/stdio.h"
#include "../../../libc/include/system.h"
#include "../../../libc/include/string.h"

#include "../../include/kernel/pic.h"
#include "../../include/kernel/pit.h"
#include "../../include/kernel/kb.h"
#include "../../include/kernel/irq.h"

irq_ptr interrupt_handlers[256];

void register_handler(uint8_t int_num, irq_ptr handler)
{
    interrupt_handlers[int_num] = handler;
}

void irq0_handler(void) 
{
    //interrupt_handlers[IRQ0](); 
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}
 
void irq1_handler(void) 
{
    interrupt_handlers[IRQ1](); 
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}

void irq2_handler(void) 
{
    printf("Inside IRQ 2\n");
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}
 
void irq3_handler(void) 
{
    printf("Inside IRQ 3\n");
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}

void irq4_handler(void) 
{
    printf("Inside IRQ 4\n");
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}
 
void irq5_handler(void) 
{
	printf("Inside IRQ 5\n");
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}

void irq6_handler(void) 
{
    printf("Inside IRQ 6\n");
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}
 
void irq7_handler(void) 
{
    printf("Inside IRQ 7\n");
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}

void irq8_handler(void) 
{
    printf("Inside IRQ 8\n");
    outb(PIC_SLAVE_COMMAND, PIC_EOI);
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}
 
void irq9_handler(void) 
{
    printf("Inside IRQ 9\n");
    outb(PIC_SLAVE_COMMAND, PIC_EOI);
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}

void irq10_handler(void) 
{
    printf("Inside IRQ 10\n");
    outb(PIC_SLAVE_COMMAND, PIC_EOI);
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}
 
void irq11_handler(void) 
{
	printf("Inside IRQ 11\n");
    outb(PIC_SLAVE_COMMAND, PIC_EOI);
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}

void irq12_handler(void) 
{
    printf("Inside IRQ 12\n");
    outb(PIC_SLAVE_COMMAND, PIC_EOI);
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}
 
void irq13_handler(void) 
{
	printf("Inside IRQ 13\n");
    outb(PIC_SLAVE_COMMAND, PIC_EOI);
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}

void irq14_handler(void) 
{
    printf("Inside IRQ 14\n");
    outb(PIC_SLAVE_COMMAND, PIC_EOI);
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}
 
void irq15_handler(void) 
{
	printf("Inside IRQ 15\n");
    outb(PIC_SLAVE_COMMAND, PIC_EOI);
    outb(PIC_MASTER_COMMAND, PIC_EOI);
}

