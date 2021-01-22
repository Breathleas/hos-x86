#assembly files
nasm -f elf ./boot/boot.asm -o ./bin/boot.o

#compile c source files
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/main.o ./kernel/main.c
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/screen.o ./kernel/screen.c


#linker scripts
ld -T link.ld -m elf_i386 -o kernel.bin ./bin/boot.o ./bin/main.o ./bin/screen.o