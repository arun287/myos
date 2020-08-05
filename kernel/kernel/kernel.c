#include <stdio.h>

#include <kernel/tty.h>

void kernel_main(void) 
{
    int a=22387;
	terminal_initialize();
    printf("Integer - %d\n",a);
}

