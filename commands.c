#include "commands.h"

void clock_event(void){
  static int counter = 0;

  if(counter >= 9600){
    PJOUT = PJOUT ^ 0xFF;
    counter = 0;
  }
  
   counter++;
}

// Basically a verilog always@(...)  block
void bit_bang(void){
  // Toggle Clock 
  clk_state ^= 1;
  
  // Toggle Clock on P1.0
  // posedge clk
  if(clk_state){
    if(cur_bit <= 32) {
      P1OUT |= CLOCK;
    }
    if(cur_bit == 32){
      P1OUT |= LE;
      cur_reg++;
      cur_reg = cur_reg % NUM_REGS;
    } else {
      P1OUT &= ~LE;
    }
    if(cur_bit > 34){
      cur_bit = 0;
    }
  // negedge clk
  } else {
    P1OUT &= ~CLOCK;
    if(cur_bit <= 31){
      if((adf4158_cmds[cur_reg] >> (31 - cur_bit)) & 0x1){
        P1OUT |= DATA;
      } else {
        P1OUT &= ~DATA;
      }
    } else{
      P1OUT &= ~DATA;
    }
    cur_bit++;
   } 
}