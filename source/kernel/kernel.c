#include "../boot/atags.h"
#include "../memory/mem.h"
#include "../graphics/framebuffer.h"
#include "../misc/blink.h"

void kernel_entry()
{
     atags_init();
     framebuffer_init(640, 480);
}
