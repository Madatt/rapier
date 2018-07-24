#ifndef ATAGS_H
#define ATAGS_H

#include "../misc/types.h"

u32 atags_ram_size;
u32 atags_ram_start;
u8 atags_ok;

u8 atags_init();

#endif
