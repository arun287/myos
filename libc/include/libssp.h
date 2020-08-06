#ifndef _LIBSSP_H
#define _LIBSSP_H 1

#include <sys/cdefs.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

#define __stack_chk_guard 0xe2dee396

#ifdef __cpluplus
extern "C"{
#endif

__attribute__((__noreturn__)) void __stack_chk_fail(void);
#ifdef __cpluplus
}
#endif
#endif


