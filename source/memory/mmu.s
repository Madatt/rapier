.section .text

.global mmu_init
mmu_init:
     mov r1,#0
     mcr p15,0,r1,c7,c7,0
     mcr p15,0,r1,c8,c7,0
     mcr p15,0,r1,c7,c10,4
     ldr r1, =0xffffffff
     mcr p15,0,r1,c3,c0,0
     mcr p15,0,r0,c2,c0,0
     ldr r1, =0x00401805
     mrc p15,0,r2,c1,c0,0
     orr r2,r2,r1
     mcr p15,0,r2,c1,c0,0

     bx lr
