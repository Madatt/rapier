#ifndef MMU_H
#define  MMU_H
#include "../misc/types.h"

extern u32 mmu_kernel_table[4096] __attribute__ ((aligned (16384)));

extern void mmu_kernel_map_section(u32 physical_address, u32 virtual_address, u32 buff, u32 cache, u32 domain, u32 ap);
extern void mmu_kernel_map_all();
extern void mmu_init(u32 address);


#endif
