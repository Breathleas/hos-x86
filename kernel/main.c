#include <ports.h>
#include <screen.h>
#include <gdt.h>
#include <idt.h>
#include <isr.h>
#include <irq.h>
#include <timer.h>
#include <keyboard.h>

int main(){
  set_cursor_pos(0,0);
	clear(COLOR_WHT, COLOR_BLK);
  kprintf("Loading kernel into memory...");
  putstr("[OK]\n", COLOR_GRN, COLOR_BLK);
  
  //install GDT, IDT, and ISRs.
  gdt_install();
  idt_install();
  isr_install();
  irq_install();
  timer_install();
  keyboard_install();
  
  //enable the interrupts
  __asm__ __volatile__("sti");

  kprintf("-------------------------------------------------------------------");
  putstr("\nWelcome to HOS, an x86 operating system written in C from scratch.\n", COLOR_DGY, COLOR_WHT);
  kprintf("-------------------------------------------------------------------\n");

  return 0;
}