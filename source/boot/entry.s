.section .text

.global start
.extern kernel_entry

start:
	mov sp, #0x80000
	bl kernel_entry

hang:
	b hang

.globl movr4
movr4:
	mov r2, r0
	bx lr
