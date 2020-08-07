#include <stdio.h>

#include "../include/kernel/tty.h"
#include "../include/kernel/gdt.h"

void kernel_main(void) 
{
    int a=22387;
    
    //__asm__("xchg %bx, %bx");
    
	terminal_initialize();
    printf("Integer - %d\n",a);
    init_gdt();
}

