#include "draw.h"
#include "framebuffer.h"

void draw_pixel(u32 x, u32 y, u32 color)
{

     u32 position = (y * framebuffer.pitch) + (x * 3);
                         
     char r = (color & 0xFF0000) >> 16;
     char g = (color & 0x00FF00) >> 8;
     char b = (color & 0x0000FF);

     *(u8*)(framebuffer.address + position) = r;
     *(u8*)(framebuffer.address + position + 1) = g;
     *(u8*)(framebuffer.address + position + 2) = b;

}
