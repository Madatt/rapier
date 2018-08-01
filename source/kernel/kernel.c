#include "../boot/atags.h"
#include "../memory/mem.h"
#include "../memory/mmu.h"
#include "../graphics/draw.h"
#include "../graphics/framebuffer.h"
#include "../graphics/font.h"
#include "../misc/blink.h"


void kernel_entry()
{
     atags_init();
     gpu_init(1920, 1080, 0);
     mmu_map_section(0x00000000, 0x00000000, 0, 0, 3, 0);
     mmu_map_section(0x20000000, 0x20000000, 0, 0, 3, 0);
     mmu_map_section(0x40000000, 0x40000000, 0, 0, 3, 0);

     u32 tmp = ((u32)(framebuffer.address)) & 0xFFF00000;
     mmu_map_section(tmp, tmp, 0, 0, 3, 0);

     mmu_init((u32)&mmu_table);


     for(u32 i = 0; i < 95; i++)
     {
          for(u32 j = 0; j < 13; j++)
          {
               for(u8 h = 0; h < 0xff; h++)
               {
                    u8 ps = (font[i][j] & ( 1 << h )) >> h;
                    if(ps)
                         draw_pixel(i*8+(7-h), 12-j, 0xFFFF00);
               }
          }
     }
}
