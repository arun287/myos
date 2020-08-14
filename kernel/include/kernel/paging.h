#ifndef _KERNEL_PAGING_H
#define _KERNEL_PAGING_H

#include <stdint.h>

typedef struct page{
    uint32_t present    :1;         // Is page present in mem
    uint32_t rw         :1;         // Read/Write enabled if bit is set
    uint32_t user       :1;         // Supervisor Level
    uint32_t accessed   :1;         // Has page been accessed since last refresh
    uint32_t dirty      :1;         // Has page been writeen to since last refresh
    uint32_t unused     :7;         // Unused and Reserved Bits
    uint32_t frame      :20;        // Frame Address (shifted right 12 bits)
}page_t;

typedef struct page_table{
    page_t pages[1024];
}page_table_t;

/*************************************************
 * the phyAddr which gives the physical address 
 * of the page directory is used to clone the 
 * page directory.
 *
 * To allow the CPU to access the pages, we need 
 * to provide the physical address of the pages. 
 * This is done through the use of tablesPhy array.
 ***************************************************/
typedef struct page_dir{
    page_table_t *tables[1024];     // Array of pointers to Page Tables
    uint32_t tablesPhy[1024];       // Array of physical address of Page Tables
    uint32_t phyAddr;               // Physical address of tablesPhy
}page_directory_t;

void init_paging();
void switch_page_dir(page_directory_t *);
page_t *get_page(uint32_t, int, page_directory_t *);
void page_fault();

#endif
