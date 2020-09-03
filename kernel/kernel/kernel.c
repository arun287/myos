#include <stdint.h>
#include <stdio.h>

#include "../include/kernel/tty.h"
#include "../include/kernel/gdt.h"
#include "../include/kernel/idt.h"
#include "../include/kernel/pit.h"
#include "../include/kernel/kb.h"
#include "../include/kernel/pmm.h"
#include "../include/kernel/vmm.h"
#include "../include/kernel/kheap.h"

extern void enable_A20();

void kernel_main(void) 
{
	terminal_initialize();
    printf("Terminal Initialized\n");
    
    enable_A20();
    printf("A20 Enabled\n");        

    init_gdt();
    printf("GDT Initialized\n");

    init_idt();
    printf("IDT Initialized\n");

    init_kb();
    printf("Keyboard Initialized\n");

    init_pmm(0x1000000); //assuming 16MB memory space
    printf("Physical Memory Management Initialized\n");

    init_vmm();
    printf("Virtual Memory Management (Paging) Initialized\n");

    //init_timer(100); 
    //printf("PIT Initialized\n");
    
    while(1);
}
