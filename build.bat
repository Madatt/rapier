@echo off

SET tt1=  --specs=nosys.specs -mcpu=arm1176jzf-s
SET tt2= -ffreestanding -nostdlib -fno-builtin  -fno-exceptions -nostartfiles -O2

echo Compiling *.s
"compiler/bin/arm-none-eabi-as.exe" "source/boot/entry.s" -o "bin/entry.o"
echo.

echo Compiling *.c
"compiler/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/kernel/kernel.c" -o "bin/kernel.o" %tt2%
"compiler/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/boot/atags.c" -o "bin/atags.o" %tt2%
"compiler/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/misc/blink.c" -o "bin/blink.o" %tt2%
"compiler/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/memory/mem.c" -o "bin/mem.o" %tt2%
"compiler/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/graphics/mailbox.c" -o "bin/mailbox.o" %tt2%
"compiler/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/graphics/framebuffer.c" -o "bin/framebuffer.o" %tt2%
echo.

echo Linking...
"compiler/bin/arm-none-eabi-gcc.exe" -nostdlib -nostartfiles -O2 -T "linker.ld"^
 "bin/entry.o"^
 "bin/kernel.o"^
 "bin/atags.o"^
 "bin/blink.o"^
 "bin/mem.o"^
 "bin/mailbox.o"^
 "bin/framebuffer.o"^
 -o "bin/kernel.elf"
echo.

echo Creating img...
"compiler/bin/arm-none-eabi-objcopy.exe" "bin/kernel.elf" -O binary "bin/kernel.img"
echo.

pause