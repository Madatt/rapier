#include "mmu.h"

u32 mmu_table[4096]  __attribute__ ((aligned (16384)));

void mmu_map_section(u32 physical_address, u32 virtual_address, u32 buff, u32 cache, u32 domain, u32 ap)
{
     u32 off = (virtual_address >> 20) << 2;
     u32* section = (u32*)(((u32) (&mmu_table)) | off);
     u32 val =  (physical_address & 0xFFF00000) | 0x02;
     val |= (buff << 2);
     val |= (cache << 3);
     val |= (domain << 5);
     val |= (ap << 10);
     *section = val;
}
