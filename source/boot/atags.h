#ifndef ATAGS_H
#define ATAGS_H

#include "../misc/types.h"

extern u32 atags_ram_size;
extern u32 atags_ram_start;
extern u8 atags_ok;

u8 atags_init();

#endif
