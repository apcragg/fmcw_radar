#include "timers.h"

static volatile uint8 clk_evt = 0;

void init_timers(void){
  TA0CTL = CLEAR_REG;
  
  TA0CTL |= TASSEL__SMCLK; // Select subsystem main clock
  TA0CTL |= MC__UP; // Cout upwards
  
  TA0CCTL0 = CLEAR_REG; 
  
  TA0CCTL0 |= CCIE; // Set interupts on capture/compare
  
  TA0CCR0 = TA0_FREQ; // Set frequency to ~9600Hz
}

uint8 has_clk_evt(void){
  return clk_evt;
}

void clear_clk_evt(void){
  clk_evt = 0;
}

#pragma vector = TIMER0_A0_VECTOR
__interrupt void timer_A0_CCR0_interupt(void)
{
  clk_evt = 1;
  bit_bang();
  TA0CCTL0 &= ~TAIFG;        // clears the interupt flag
}