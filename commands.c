#include "commands.h"

void clock_event(void){
  static int counter = 0;

  if(counter >= (9600 / 4)){
    PJOUT = PJOUT ^ 0xFF;
    counter = 0;
  }
   counter++;
}

// Basically a verilog always@(...)  block
void bit_bang(void){
  if(!done){
    // Toggle Clock 
    clk_state ^= 1;

    // Toggle Clock on P1.0
    // posedge clk
    if(clk_state){
      // Only run clock during data transmission
      if(cur_bit <= 32) {
        P1OUT |= CLOCK;
      }
      // Once entire register has been shifted out, advance to next register
      // Raise latch enable for one clock cycle 
      if(cur_bit == 32){
        P1OUT |= LE;
        cur_reg++;
        if(cur_reg == NUM_REGS){
          done = 1;
        }
        cur_reg = cur_reg % NUM_REGS;
      } else {
        P1OUT &= ~LE;
      }
      // Wait a bit, then start transmitting next register
      if(cur_bit > 34){
        cur_bit = 0;
      }
    // negedge clk
    } else {
      // Clock defaults to low
      P1OUT &= ~CLOCK;
      // Ensure only valid bits are shifted out
      if(cur_bit <= 31){
        if((adf4158_cmds[cur_reg] >> (31 - cur_bit)) & 0x1){
          P1OUT |= DATA;
        } else {
          P1OUT &= ~DATA;
        }
      } else{
        // Data line defaults to low
        P1OUT &= ~DATA;
      }
      cur_bit++;
    } 
  }
}