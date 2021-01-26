#ifndef __SYSTEM_H
#define __SYSTEM_H

//-----------------------------------------------------------------------------------------------------------------
/* MAIN.C */
extern unsigned char *memcpy(unsigned char *dest, const unsigned char *src, int count);
extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
extern int strlen(const char *str);
extern unsigned char in_port_byte(unsigned short port);
extern void out_port_byte(unsigned short port, unsigned char data);

//-----------------------------------------------------------------------------------------------------------------
/* SCREEN.C */
//define basic constants
#define VGA_START 0xb8000 //VGA start address
#define VGA_WIDTH 80 //these are max coloumns in VGA
#define VGA_HEIGHT 25 //these are max rows in VGA
#define VGA_EXTENT 80*25

//---------------------------------------------------
//defining available colors
#define COLOR_BLK 0     // Black
#define COLOR_BLU 1     // Blue
#define COLOR_GRN 2     // Green
#define COLOR_CYN 3     // Cyan
#define COLOR_RED 4     // Red
#define COLOR_PRP 5     // Purple
#define COLOR_BRN 6     // Brown
#define COLOR_GRY 7     // Gray
#define COLOR_DGY 8     // Dark Gray
#define COLOR_LBU 9     // Light Blue
#define COLOR_LGR 10    // Light Green
#define COLOR_LCY 11    // Light Cyan
#define COLOR_LRD 12    // Light Red
#define COLOR_LPP 13    // Light Purple
#define COLOR_YEL 14    // Yellow
#define COLOR_WHT 15    // White

//---------------------------------------------------

//I/O ports which map the screen cursor position can be queried
//from port 0x3d4 with value 14 to request the cursor position high byte
//and we also query the same port with value 15 in the low byte
//when this port is queried, the result is saved in 0x3d5

//cursor ports:
//command port = 0x3d4 query the cursor position here
//data port = 0x3d5 read from here
#define CURSOR_PORT_COMMAND (unsigned short) 0x3d4
#define CURSOR_PORT_DATA (unsigned short) 0x3d5

//---------------------------------------------------
//define a single character struct with close packing
typedef struct __attribute__((packed)){
	char character;
	char style;
} vga_char;


//apply foreground and background colors to the character
unsigned char vga_color(const unsigned char fg_color, const unsigned char bg_color);

//clear the window or screen with a color
void clear(const unsigned char fg_color, const unsigned char bg_color);

//print a character to the screen
void putchar(const char character, const unsigned char fg_color, const unsigned char bg_color);

//print a string to the screen
void putstr(const char *string, const unsigned char fg_color, const unsigned char bg_color);

//get the cursor position
unsigned short get_cursor_pos();

//show or hide cursor functions
void show_cursor();
void hide_cursor();

//set the cursor position
void advance_cursor();
void set_cursor_pos(unsigned char x, unsigned char y);

void kprintf(const char *string);

//scroll line
void scroll_line();
//----------------------------------------------------------------------------------------------------------------
/* GDT.C */
void gdt_set_gate(int num, unsigned long base, unsigned long limit, unsigned char access, unsigned char gran);
void gdt_install();

//-----------------------------------------------------------------------------------------------------------------
/* IDT.C */
void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);
void idt_install();

//----------------------------------------------------------------------------------------------------------------
/* ISR.C */
void isr_install();
//the following is a data structure that defines how stack looks when an ISR is running
//as we know, we push the pointer of stack on to the stack when an ISR occurs, to handle those interrutps using our
//C fault handler we use the following to show how stack looks like.
struct regs
{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
};

//----------------------------------------------------------------------------------------------------------------
/* IRQ.C */
void irq_install();
void irq_install_handler();
void irq_uninstall_handler();

//----------------------------------------------------------------------------------------------------------------
/* TIMER.C */
void timer_install();

#endif