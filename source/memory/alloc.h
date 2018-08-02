#ifndef ALLOC_H
#define ALLOC_H

#include "mem.h"
#include "../misc/types.h"

extern u32 memory_start;
extern u32 memory_end;


typedef struct Tmemory_block_t
{
     struct Tmemory_block_t* next;
     u32 size;
     u32 free;
     u8 last;
}memory_block_t;

extern memory_block_t* memory_block_f;
extern memory_block_t* memory_last_free;


extern void memory_init();
extern void* memory_allocate(u8 bytes);
extern void memory_free(void* address);



#endif
