# UNIX-like OS in C

Following tutorials from [wiki.osdev.org](http://wiki.osdev.org/)

![image](https://cloud.githubusercontent.com/assets/2051361/12076705/5d493eee-b16b-11e5-852c-8136e20fa0d6.png)

----

Run `build.sh`. i686-elf-gcc is required for cross compilation.

You can assemble a bootable image:

`nasm -felf boot.asm -o boot.o`

`i686-elf-gcc -c src/kernel.c -o build/kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra`

`i686-elf-gcc -T linker.ld -o boot/os.bin -ffreestanding -O2 -nostdlib boot.o build/kernel.o -lgcc`

`mkisofs -R -b boot/grub/stage2_eltorito.bin -no-emul-boot -boot-load-size 4 -boot-info-table -o os.iso ./os`
