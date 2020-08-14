#include <stdint.h>
#include <stdio.h>

#include "../include/kernel/tty.h"
#include "../include/kernel/gdt.h"
#include "../include/kernel/idt.h"
#include "../include/kernel/pit.h"
#include "../include/kernel/kb.h"
#include "../include/kernel/paging.h"
#include "../include/kernel/kheap.h"

void kernel_main(void) 
{
	terminal_initialize();
    printf("Terminal Initialized\n");

    init_gdt();
    printf("GDT Initialized\n");

    init_idt();
    printf("IDT Initialized\n");

    init_kb();
    printf("Keyboard Initialized\n");

    init_paging();
    printf("Paging Initialized\n");

    //init_timer(100); 
    //printf("PIT Initialized\n");
    
    while(1);
}
