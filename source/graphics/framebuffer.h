#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "../misc/types.h"

typedef struct
{
     u32 width;
     u32 height;
     u32 vwidth;
     u32 vheight;
     u32 pitch;
     u32 depth;
     u32 xoffset;
     u32 yoffset;
     u32 address;
     u32 size;

}framebuffer_t;

extern u32 doublebuffering;
extern u32 framebuffer_switch;

extern framebuffer_t framebuffer  __attribute__((aligned (16)));

extern void gpu_init(u32 width, u32 height, u32 doubleb);
extern void framebuffer_swap();
extern void framebuffer_init();


#endif
