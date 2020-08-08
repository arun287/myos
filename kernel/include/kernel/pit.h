#ifndef _KERNEL_PIT_H
#define _KERNEL_PIT_H

#include <stdint.h>

#define PIT_CH0 0x40
#define PIT_CH1 0x41
#define PIT_CH2 0x42
#define PIT_COMMAND 0x43

void init_timer(uint32_t);
void pit_callback();

#endif
