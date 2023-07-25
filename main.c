#include "nios2_ctrl_reg_macros.h"
// function prototypes
int main(void);
void interrupt_handler(void);
void the_exception (void);
int sevenSegment(int num);
/* declare glabals*/
int flag=0;
/* Declare volatile pointers to I/O registers. This will ensure that the resulting
code will bypass the cache*/
volatile int * MSB3 = (int *) 0x000090a0;
volatile int * GREEN_LEDS = (int *) 0x00009090;
volatile int * SW2 = (int *) 0x00009080;
volatile int * SEVEN = (int *) 0x00009060;
volatile int * UART = (int *) 0x00009000;
volatile int * RED_LEDS = (int *) 0x00009070;
volatile int * MSB1 = (int *) 0x00009050;
volatile int * MSB2 = (int *) 0x00009040;
volatile int * Channel1 = (int *) 0x00009030;
volatile int * Channel2 = (int *) 0x00009020;
/********************************************************************************
* This program demonstrates use of the DE2 Basic Computer RS232 serial i/f.
********************************************************************************/
int main(void)
{
// set up rising edge triggered interrupts for the counter PIO input // enable counter MSB interrupt
*(MSB3 + 0x2 ) = 0x1;
// set up RS232 interrupt for read ready
*(UART + 0x02) = 0x80;
// enable interrupt for irrdy
*(UART + 0x03) = 0x80;
// set interrupt mask bit for counter IRQ level 0 (counter) and 1 (RS232)
NIOS2_WRITE_IENABLE(0x03);
// enable Nios II interrupts (presumably PIE bit in status set to 1)
NIOS2_WRITE_STATUS( 0x1 );
int prevMSB1 = *(MSB1);
int currentMSB1;
int fallcount = 0;
static int message[8] = {3,2,2,8,1,0,1,3};
int pointer;
*(SEVEN) = 0xFFFFFFF;
 while(1)
 { // normal code infinite loop
 currentMSB1 = *(MSB1);
 if (currentMSB1 && !prevMSB1)
 {
 *(GREEN_LEDS) = *(GREEN_LEDS) + 0x01;
 pointer = (*(GREEN_LEDS)-1) % 8;

 *(UART + 0x01) = message[pointer];
 }

 if(!currentMSB1 && prevMSB1)
 {
 fallcount = (fallcount + 1)%10;
 *(SEVEN) = *(SEVEN)-(*(SEVEN)%(128)) + sevenSegment(fallcount);
 }

 prevMSB1 = currentMSB1;

 } // end of normal code infinite loop
}
int sevenSegment(int num) {
 switch(num)
 {
 case 0:
 return 0x40;
 case 1:
 return 0x79;
 case 2:
 return 0x24;
 case 3:
 return 0x30;
 case 4:
 return 0x19;
 case 5:
 return 0x12;
 case 6:
 return 0x02;
 case 7:
 return 0x78;
 case 8:
 return 0x00;
 case 9:
 return 0x10;
 }
}