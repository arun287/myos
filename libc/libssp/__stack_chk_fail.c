#include <stdio.h>
#include <stdlib.h>

#include "../include/libssp.h"

#define __stack_chk_guard 0xe2dee396

__attribute__((__noreturn__)) void __stack_chk_fail(void)
{
#if __STDC_HOSTED__
	abort();
#elif __is_myos_kernel
	panic("Stack smashing detected");
#endif

	while (1) { }
	__builtin_unreachable();
}
