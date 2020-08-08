#ifndef _SYSTEM_H
#define _SYSTEM_H 1

#include <sys/cdefs.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"{
#endif

    void outb(uint16_t, uint8_t);
#ifdef __cplusplus
}
#endif
#endif
