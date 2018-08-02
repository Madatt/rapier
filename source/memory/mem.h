#ifndef MEM_H
#define MEM_H

#include "../misc/types.h"

#define GPU_OFFSET 0x40000000

extern void* _end;
extern void movr4 (u32);

extern void memory_barrier();

extern void memory_write_u32(u32 address, u32 data);
extern u32 memory_read_u32(u32 address);

extern u32 address_to_bus(u32 address);
extern u32 address_to_arm(u32 address);
#endif
