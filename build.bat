@echo off

SET tt1=  --specs=nosys.specs -mcpu=arm1176jzf-s
SET tt2= -ffreestanding -nostdlib -fno-builtin  -fno-exceptions -nostartfiles -O2

echo Compiling *.s
"compiler2/bin/arm-none-eabi-as.exe" "source/boot/entry.s" -o "bin/entry.o"
"compiler2/bin/arm-none-eabi-as.exe" "source/memory/mmu.s" -o "bin/mmu_s.o"
echo.

echo Compiling *.c
"compiler2/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/kernel/kernel.c" -o "bin/kernel.o" %tt2%
"compiler2/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/boot/atags.c" -o "bin/atags.o" %tt2%
"compiler2/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/memory/mem.c" -o "bin/mem.o" %tt2%
"compiler2/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/graphics/mailbox.c" -o "bin/mailbox.o" %tt2%
"compiler2/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/graphics/framebuffer.c" -o "bin/framebuffer.o" %tt2%
"compiler2/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/graphics/draw.c" -o "bin/draw.o" %tt2%
"compiler2/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/memory/mmu.c" -o "bin/mmu.o" %tt2%
"compiler2/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/memory/alloc.c" -o "bin/alloc.o" %tt2%
"compiler2/bin/arm-none-eabi-gcc.exe" %tt1% -c "source/misc/lib.c" -o "bin/lib.o" %tt2%
echo.

echo Linking...
"compiler2/bin/arm-none-eabi-gcc.exe" -nostdlib -nostartfiles -O2 -T "linker.ld"^
 "bin/entry.o"^
 "bin/kernel.o"^
 "bin/atags.o"^
 "bin/mem.o"^
 "bin/mailbox.o"^
 "bin/framebuffer.o"^
 "bin/draw.o"^
 "bin/mmu.o"^
 "bin/mmu_s.o"^
 "bin/lib.o"^
 "bin/alloc.o"^
 -o "bin/kernel.elf"
echo.

echo Creating img...
"compiler2/bin/arm-none-eabi-objcopy.exe" "bin/kernel.elf" -O binary "bin/kernel.img"
echo.

pause
