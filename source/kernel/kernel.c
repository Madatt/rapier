#include "../boot/atags.h"
#include "../memory/mem.h"
#include "../memory/mmu.h"
#include "../memory/alloc.h"
#include "../graphics/draw.h"
#include "../graphics/framebuffer.h"
#include "../misc/lib.h"



void kernel_entry()
{
     atags_init();
     gpu_init(1920, 1080, 0);

     mmu_map_section(0x00000000, 0x00000000, 0, 0, 3, 0);
     mmu_map_section(0x10000000, 0x10000000, 0, 0, 3, 0);
     mmu_map_section(0x20000000, 0x20000000, 0, 0, 3, 0);
     mmu_map_section(0x40000000, 0x40000000, 0, 0, 3, 0);

     u32 tmp = ((u32)(framebuffer.address)) & 0xFFF00000;
     mmu_map_section(tmp, tmp, 0, 0, 3, 0);

     mmu_init((u32)&mmu_table);

     memory_init();

     char test[16];

     u32 ad = (u32)memory_allocate(12);

     hexstring(ad,test);
     draw_text(32,32, 0xFFFFFF, test);

     hexstring(sizeof(memory_block_t),test);
     draw_text(32,52, 0xFFFFFF, test);

     hexstring((u32)(memory_block_f->next),test);
     draw_text(32,72, 0xFFFFFF, test);
}
