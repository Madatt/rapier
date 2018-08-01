#include "draw.h"
#include "framebuffer.h"
#include "font.h"

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

void draw_char(u32 x, u32 y, u32 color, u8 chr)
{
     for(u8 i = 0; i < 13; i++)
     {
          for(u8 j = 0; j < 8; j++)
          {
               u8 ps = (font[chr-32][i] & ( 1 << j )) >> j;
               if(ps)
                    draw_pixel((7-j)+x, 12-i+y, color);
          }
     }

}

void draw_text(u32 x, u32 y, u32 color, u8 * txt)
{
     u8 ps = 0;
     for(u8* i = txt; *i != '\0'; i++)
     {
          draw_char(x+8*ps+2*ps, y, color, *i);
          ps++;
     }
}
