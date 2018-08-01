#ifndef ATAGS_H
#define ATAGS_H

#include "../misc/types.h"


typedef struct
{
     u32 size;
     u32 start;
}atag_mem_t;

extern u8 atags_ok;
extern atag_mem_t atag_mem;

u8 atags_init();

#endif
