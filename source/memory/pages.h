#ifndef PAGE_H
#define PAGE_H

#include "../misc/types.h"

typedef struct
{
     u8 kernel: 1;
     u8 free: 1;
     u32 unu: 30;
}page_t;

extern page_t* pages;

extern void memory_pages_init();
extern void* memory_page_allocate();
extern void memory_page_free(void* address);






#endif
