if [ ! -d bin ] 
then
    mkdir -p bin
fi

#assembly files
nasm -f elf ./boot/boot.asm -o ./bin/boot.o

#compile c source files
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/main.o ./kernel/main.c
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/ports.o ./kernel/ports.c
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/screen.o ./kernel/screen.c
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/mem.o ./kernel/lib/mem.c
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/gdt.o ./kernel/gdt.c
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/idt.o ./kernel/idt.c
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/isr.o ./kernel/isr.c
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/irq.o ./kernel/irq.c
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/timer.o ./kernel/timer.c
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/keyboard.o ./kernel/keyboard.c
gcc -m32 -elf_i386 -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin -I./kernel/include -c -o ./bin/string.o ./kernel/lib/string.c


#linker scripts
ld -T link.ld -m elf_i386 -o os.bin ./bin/boot.o ./bin/main.o ./bin/ports.o ./bin/screen.o ./bin/mem.o ./bin/gdt.o ./bin/idt.o ./bin/isr.o ./bin/irq.o ./bin/timer.o ./bin/keyboard.o ./bin/string.o

#make iso file
mkdir -p isodir/boot/grub
cp os.bin isodir/boot/os.bin
cp grub.cfg isodir/boot/grub/grub.cfg
grub-mkrescue -o hos-x86.iso isodir
