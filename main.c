#include "msp430fr5739.h"
#include "globals.h"
#include "ports.h"
#include "clocks.h"
#include "timers.h"
#include "commands.h"

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  // Enable global interrupts
  __bis_SR_register(GIE); 
  
  init_ports();
  init_clocks();
  init_timers(); 
  
  while(1){
    if(has_clk_evt()){
      clock_event();
      clear_clk_evt();
    }
  }
}

