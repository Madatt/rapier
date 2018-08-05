#ifndef ALLOC_H
#define ALLOC_H

#include "mem.h"
#include "../misc/types.h"

extern u32 heap_start;
extern u32 heap_size;
extern u32 heap_header_size;

typedef struct Theap_t
{
     struct Theap_t* next;
     u32 address;
     u32 size;
     u32 free;
}heap_t;

extern heap_t* heap_f;


extern void memory_heap_init();
extern void* memory_heap_allocate(u32 bytes);
extern void memory_heap_free(void* address);



#endif
