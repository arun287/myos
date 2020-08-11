#ifndef _KERNEL_KB_H
#define _KERNEL_KB_H

#define KB_DATA_REG 0x60
#define KB_CNTRL_REG 0x64

void kb_callback();
void init_kb();

#endif
