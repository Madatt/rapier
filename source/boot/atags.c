#include "atags.h"

#define ATAGS_START 0x100

#define ATAG_CORE 0x54410001
#define ATAG_MEM 0x54410002
#define ATAG_NONE 0x00000000

atag_mem_t atag_mem;
u8 atags_ok;


u8 atags_init()
{
     u32* first_size = (u32*) ATAGS_START;
     u32* first_value = (u32*) (ATAGS_START+0x4);


     if(*first_size != 5 && *first_value != ATAG_CORE)
     {
          atags_ok=0;
          return 0;
     }

     atags_ok = 1;
     u32* current = (u32*) (ATAGS_START + (0x5 * 0x4));
     u8 lv = 0;

     while(!lv)
     {
          u32 sz = *current;
          current += 0x1;

          u32 sw = (u32) *current;
          switch (sw)
          {
               case ATAG_NONE:
                    lv = 1;
               break;

               case ATAG_MEM:
                    current += 0x1;
                    atag_mem.size=*current;

                    current += 0x1;
                    atag_mem.start=*current;

                    current += 0x1;
               break;

               default:
                    current += (sz - 0x1);
          }


     }

     return 1;
}
