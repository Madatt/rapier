#include "mem.h"

void memory_barrier()
{
	asm("mcr p15, 0, ip, c7, c5, 0");
	asm("mcr p15, 0, ip, c7, c5, 6");
	asm("mcr p15, 0, ip, c7, c10, 4");
	asm("mcr p15, 0, ip, c7, c5, 4");
}

void memory_write_u32(u32 address, u32 data)
{
     u32* tmp = (u32*) address;
     *tmp = data;
}


u32 memory_read_u32(u32 address)
{
     u32* tmp = (u32*) address;
     return (u32) *tmp;
}

u32 address_to_bus(u32 address)
{
	return (u32)(address + GPU_OFFSET);
}

u32 address_to_arm(u32 address)
{
	if(address > GPU_OFFSET)
		return (u32)(address - GPU_OFFSET);

	return (u32)(address);
}
