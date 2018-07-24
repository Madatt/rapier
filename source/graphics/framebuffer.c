#include "framebuffer.h"
#include "mailbox.h"
#include "../memory/mem.h"
#include "../misc/blink.h"

framebuffer_t frbf __attribute__((aligned (16)));

void framebuffer_init(u32 width, u32 height)
{
     frbf.width = width;
     frbf.height = height;
     frbf.vwidth = width;
     frbf.vheight = height;
     frbf.depth = 24;
     frbf.pitch = 0;

     mailbox_write((u32)&frbf, CHANNEL_FRAMEBUFFER);

     u32 res = 0xFF;
     res = mailbox_read(CHANNEL_FRAMEBUFFER);

}
