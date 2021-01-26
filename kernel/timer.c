#include <system.h>

//The timer has 3 channels, 0,1,2
//0 is for IRQ0
//1 is system specific and 2 is for speaker
//2 can be used to create sound like
//these three channels are present at 0x40, 0x41, 0x42 and 0x43 is the command register

//let's keep track of number of ticks elapsed
int ticks = 0;

//to increase the "ticks" variable, we increment it evrytime the timer fires.
//the timer PIT is connected to IRQ0, so evrytime it fires, we increment it
//by default, the timer fires 18.222 times/second.
void timer_handler(struct regs *r){
    //increment number of ticks
    ticks++;
    /*if(ticks%18 == 0){
        putstr("One second has passed.\n", COLOR_YEL, COLOR_BLK);
    }*/
}

//let's install timer handler into IRQ0
void timer_install(){
    kprintf("Installing Timer...");
    irq_install_handler(0, timer_handler);
    putstr("[OK]\n", COLOR_GRN, COLOR_BLK);
}