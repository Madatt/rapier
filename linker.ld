ENTRY(start)
SECTIONS
{
	. = 0x8000;

    .text : { *(.text*) }
    . = ALIGN(4096);

    .data : { *(.data*) }
    . = ALIGN(4096);

    .bss : { *(.bss*) }
    . = ALIGN(4096);

    _end = .;
}
