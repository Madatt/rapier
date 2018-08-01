#include "../boot/atags.h"
#include "../memory/mem.h"
#include "../memory/mmu.h"
#include "../graphics/draw.h"
#include "../graphics/framebuffer.h"
#include "../misc/lib.h"



void kernel_entry()
{
     atags_init();
     gpu_init(1920, 1080, 0);
     mmu_map_section(0x00000000, 0x00000000, 0, 0, 3, 0);
     mmu_map_section(0x20000000, 0x20000000, 0, 0, 3, 0);
     mmu_map_section(0x40000000, 0x40000000, 0, 0, 3, 0);

     u32 tmp = ((u32)(framebuffer.address)) & 0xFFF00000;
     mmu_map_section(tmp, tmp, 0, 0, 3, 0);

     char test[16];
     hexstring(atag_mem.size,test);

     mmu_init((u32)&mmu_table);

     draw_text(32, 32, 0xFFFFFF, test);
}
