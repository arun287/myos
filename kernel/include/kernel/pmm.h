#ifndef _KERNEL_PMM_H
#define _KERNEL_PMM_H

#include <stdint.h>
#include "../kernel/vmm.h"

#define WORD_OFFSET(n) (n/32)
#define BIT_OFFSET(n) (n%32)

//Functions required to manipulate BITMAP used for PMM
void set_frame(uint32_t);
void clear_frame(uint32_t);
uint32_t check_frame(uint32_t);
uint32_t first_free_frame();

//Functions required for VMM
void alloc_frame(page_t *, int, int);
void free_frame(page_t *);

void init_pmm(uint32_t);

#endif
