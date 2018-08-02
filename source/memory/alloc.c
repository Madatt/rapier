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
     memory_block_f->size = 0;
     memory_block_f->last = 1;
     memory_block_f->free = 1;
     memory_last_free = memory_block_f;
}

void* memory_allocate(u32 bytes)
{
     memory_block_t* now = (memory_block_t*) memory_start;
     u32 hs = sizeof(memory_block_t);

     while(1)
     {
          if(now->free == 1 && now->last == 0 && now->size >= bytes)
          {
               u32 olds = now->size;
               u8 oldl = now->last;
               memory_block_t* oldn = now->next;

               now->free = 0;
               now->size = bytes;
               now->next = (memory_block_t*)(hs+bytes+(u32)now);
               if(olds-bytes > hs)
               {
                    now->next->free = 1;
                    now->next->size = olds-hs-bytes-hs;
                    now->next->next = oldn;
               }
               else
               {
                    now->next = oldn;
               }
               return (void*) ((u32)now+hs);
          }
          else if(now->free == 1 && now->last == 1)
          {
               if(memory_end - (u32)now - hs > bytes+hs)
               {
                    now->free = 0;
                    now->size = bytes;
                    now->last = 0;

                    now->next = (memory_block_t*)(hs+bytes+(u32)now);
                    now->next->size = 0;
                    now->next->free = 1;
                    now->next->last = 1;

                    return (void*) ((u32)now+hs);
               }
               else
               {
                    return (void*) 0;
               }
          }
          else
          {
               now = now->next;
          }
     }
}

void memory_free(void* address)
{
     u32 hs = sizeof(memory_block_t);
     memory_block_t* now = (void*)((u32)address-hs);
     now->free = 1;
}
