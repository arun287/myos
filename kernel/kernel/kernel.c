#include <stdio.h>

#include "../include/kernel/tty.h"
#include "../include/kernel/gdt.h"

void kernel_main(void) 
{
	terminal_initialize();
    printf("Terminal Initialized\n");

    init_gdt();
    printf("GDT Initialized\n");
}

