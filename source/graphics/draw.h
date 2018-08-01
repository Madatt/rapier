#ifndef DRAW_H
#define DRAW_H

#include "../misc/types.h"

extern void draw_pixel(u32 x, u32 y, u32 color);
extern void draw_char(u32 x, u32 y, u32 color, u8 chr);
extern void draw_text(u32 x, u32 y, u32 color, u8 * txt);

#endif
