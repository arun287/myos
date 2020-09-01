#include "../../../libc/include/stdio.h"
#include "../../../libc/include/system.h"

#include "../../include/kernel/pit.h"
#include "../../include/kernel/irq.h"

uint32_t tick = 0;

void pit_callback()
{
    tick++;
}

void init_timer(uint32_t frequency)
{
    register_handler(IRQ0, &pit_callback);

    uint32_t divisor = 1193180 / frequency;
    
    //Send the command byte
    outb(PIT_COMMAND, 0x36);

    //Send the lower and higher bytes of the divisor
    outb(PIT_CH0, (uint8_t)(divisor & 0xFF));
    outb(PIT_CH0, (uint8_t)((divisor>>8) & 0xFF));
}
