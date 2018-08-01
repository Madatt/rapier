#include "framebuffer.h"
#include "mailbox.h"
#include "../memory/mem.h"

u32 doublebuffering;
u32 framebuffer_switch;

framebuffer_t framebuffer __attribute__((aligned (16)));



void gpu_init(u32 width, u32 height, u32 doubleb)
{
     doublebuffering = doubleb;
     framebuffer_switch = 0;

     framebuffer.width = width;
     framebuffer.vwidth = width;
     framebuffer.height = height;
     framebuffer.vheight = height;
     framebuffer.pitch = 0;
     framebuffer.depth = 24;
     framebuffer.xoffset = 0;
     framebuffer.yoffset = 0;
     framebuffer.address = 0;

     framebuffer_init();
}

void framebuffer_init()
{
     mailbox_write(address_to_bus((u32)&framebuffer), CHANNEL_FRAMEBUFFER);
     u32 res = 0;
     res = mailbox_read(CHANNEL_FRAMEBUFFER);
     framebuffer.address = address_to_arm(framebuffer.address);

}

void framebuffer_swap()
{
     if(!doublebuffering) return;

     if(framebuffer_switch)
          framebuffer.yoffset = 0;
     else
          framebuffer.yoffset = framebuffer.height;

     framebuffer_switch = !framebuffer_switch;

}
