#include <system.h>

unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count)
{
  int i;
  for (i=0; i<count;i++) dest[i]=src[i];
  return dest;
}

unsigned char *memset(unsigned char *dest, unsigned char val, int count)
{
  int i;
  for (i=0; i<count;i++) dest[i]=val;
  return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, int count)
{
  int i;
  for (i=0; i<count;i++) dest[i]=val;
  return dest;
}

int strlen(const char *str)
{
  int i;
  for (i=0;;i++) if (str[i] == '\0') return i;
}

unsigned char in_port_byte(unsigned short port){
    unsigned char result;
    __asm__ volatile("in %%dx, %%al": "=a"(result) : "d" (port));

    return result;
}

void out_port_byte(unsigned short port, unsigned char data){
	__asm__ volatile("out %%al, %%dx" : : "a" (data), "d" (port));
}

int main(){
    set_cursor_pos(0,0);
	clear(COLOR_WHT, COLOR_BLK);
    
	const char *welcome = "\nHello, There! you are now in Kernel!\n\n";
	const char *first = "It now has a more advanced VGA driver!\n";
	const char *second = "and supports special characters like\t tab and\n newline.\n\n";

	putstr(welcome, COLOR_GRN, COLOR_BLK);
	putstr(first, COLOR_WHT, COLOR_BLK);
	putstr(second, COLOR_WHT, COLOR_BLK);

    return 0;
}