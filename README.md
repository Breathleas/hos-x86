### HOS-x86 an x86 operating system written from scratch

### How to Build?

Currently you need ```NASM```, ```GCC``` and ```QEMU``` to build the image file.

Install the packages using the following commands.
Note: These commands will only work on Ubuntu/Debian based systems.
```
apt-get install nasm
apt-get install gcc
apt-get install qemu
```

To build the image, run the following command
```
sh build.sh or ./build.sh
```

To emulate the os image, run the following command
```
qemu-system-i386 -kernel kernel.bin
```

Here's how it looks

![img file](https://github.com/jaychandra6/hos-x86/blob/main/os.png)

The kernel is based on this [tutorial](http://www.osdever.net/bkerndev/Docs/title.htm)