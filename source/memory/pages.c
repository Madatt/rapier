#include "pages.h"
#include "heap.h"
#include "../boot/atags.h"

page_t* pages;

void memory_pages_init()
{
     pages = (page_t*)(heap_start+heap_size);

     u32 n = atag_mem.size/4096;

     for(u32 i = 0; i < n; i++)
     {
          pages[i].free = 1;
          pages[i].kernel = 0;
     }

     u32 kn = (u32)&pages[n]/4096;

     for(u32 i = 0; i < kn; i++)
     {
          pages[i].free = 0;
          pages[i].kernel = 1;
     }

}

void* memory_page_allocate()
{
     u32 n = atag_mem.size/4096;

     for(u32 i = 0; i < n; i++)
     {
          if(pages[i].free == 1)
          {
               pages[i].free = 0;
               return (void*) (i*4096);
          }
     }

     return (void*) 0;
}

void memory_page_free(void* address)
{
     u32 i = (u32)address/4096;

     pages[i].free = 1;
}
