#include <stdio.h>

#include "../include/kernel/tty.h"
#include "../include/kernel/gdt.h"
#include "../include/kernel/idt.h"
#include "../include/kernel/pit.h"

void kernel_main(void) 
{
	terminal_initialize();
    printf("Terminal Initialized\n");

    init_gdt();
    printf("GDT Initialized\n");

    init_idt();
    printf("IDT Initialized\n");

    init_timer(100); 
    
    while(1);
}
