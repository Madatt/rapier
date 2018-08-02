#include "alloc.h"
#include "../boot/atags.h"

u32 memory_start;
u32 memory_end;
memory_block_t* memory_last_free;

memory_block_t* memory_block_f;


void memory_init()
{
     u32 al = (u32)(&_end) % 0x100000;
     al = (u32)(&_end) + (0x100000 - al);

     memory_start = al;
     memory_end = atag_mem.size;

     memory_block_f = (memory_block_t*) memory_start;
     memory_block_f->free = 1;
     memory_last_free = memory_block_f;
}

void memory_allocate(u32 bytes)
{
     //todo
}
