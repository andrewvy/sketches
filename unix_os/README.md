# UNIX-like OS in C

Following tutorials from [wiki.osdev.org](http://wiki.osdev.org/)

----

You can assemble a bootable image:

`nasm -felf boot.asm -o boot.o`

`i686-elf-gcc -c src/kernel.c -o build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra`

`i686-elf-gcc -T linker.ld -o boot/os.bin -ffreestanding -O2 -nostdlib boot.o build/kernel.o -lgcc`

`grub-mkrescue -o boot/os.iso boot`
