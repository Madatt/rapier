#include "heap.h"
#include "../boot/atags.h"

u32 heap_start;
u32 heap_size;
u32 heap_header_size;

heap_t* heap_f;


void memory_heap_init()
{
     u32 al = (u32)(&_end) % 0x400;
     al = (u32)(&_end) + (0x400 - al);

     heap_start = al;
     heap_size = 0x00400000;

     heap_header_size = sizeof(heap_t);

     heap_f = (heap_t*) heap_start;
     heap_f->size = heap_size - heap_header_size;
     heap_f->next = (void*) 0;
     heap_f->free = 1;
}

void* memory_heap_allocate(u32 bytes)
{
     for(heap_t* i = heap_f; i->next != (void*)0; i = i->next)
     {
          if(i->free == 1 && i->size >= bytes)
          {
               u32 olds = i->size;
               heap_t* oldn = i->next;

               i->free = 0;
               i->size = bytes;
               i->next = (heap_t*) (heap_header_size+bytes+(u32)i);

               if(olds-bytes > heap_header_size)
               {
                    i->next->free = 1;
                    i->next->size = olds-bytes-2*heap_header_size;
                    i->next->next = oldn;
               }
               else
               {
                    i->next = oldn;
               }

               return (void*) ((u32)i+heap_header_size);
          }
     }
     return (void*) 0;
}

void memory_free(void* address)
{
     heap_t* i = (heap_t*)((u32)address-heap_header_size);
     i->free = 1;
}
