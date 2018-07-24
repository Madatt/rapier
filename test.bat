@echo off
"C:\Program Files\qemu\qemu-system-arm.exe" -monitor stdio -machine raspi2 -m 1G -kernel "bin/kernel.elf"
pause
