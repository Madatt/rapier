.global start
.extern kernel_entry

start:
	mov sp, #0x80000
	bl kernel_entry

hang:
	b hang


.globl PUT32
PUT32:
	str r1,[r0]
    	bx lr

.globl GET32
GET32:
    	ldr r0,[r0]
    	bx lr

.globl dummy
dummy:
	bx lr

.globl movr4
movr4:
	mov r2, r0
	bx lr
