#include "ports.h"

void init_ports(void){
  init_port_1();
  init_port_j();
}

void init_port_1(void){
  P1SEL0 = GPIO_SEL0; // Set P1 to GPIO
  P1SEL1 = GPIO_SEL1;
  
  P1DIR |= GPIO_OUT; // Set P1 to Output
  
  P1OUT &= CLEAR_REG; // Set P1 low 
}

void init_port_j(void){
  PJSEL0 = GPIO_SEL0; // Set PJ to GPIO
  PJSEL1 = GPIO_SEL1;
  
  PJDIR |= GPIO_OUT; // Set PJ to Output
  
  PJOUT = 0x9; // Set PJ.3 high 
}