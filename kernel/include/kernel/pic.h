#ifndef _KERNEL_PIC_H
#define _KERNEL_PIC_H

#include <stdint.h>

#define PIC_MASTER_COMMAND 0x20
#define PIC_MASTER_DATA 0x21

#define PIC_SLAVE_COMMAND 0xA0
#define PIC_SLAVE_DATA 0xA1

#define ICW1 0x11
#define ICW4 0x01

#define PIC_EOI 0x20

#endif
