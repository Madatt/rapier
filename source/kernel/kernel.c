#include "../boot/atags.h"
#include "../memory/mem.h"
#include "../memory/mmu.h"
#include "../memory/heap.h"
#include "../memory/pages.h"
#include "../graphics/draw.h"
#include "../graphics/framebuffer.h"
#include "../misc/lib.h"



void kernel_entry()
{
     atags_init();

     memory_heap_init();
     memory_pages_init();

     framebuffer_init(1280, 720);

     draw_text(32, 32, 0xFFFFFF, "Test 123 !@#$");
}
