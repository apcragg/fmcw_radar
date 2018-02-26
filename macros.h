#ifndef MACROS_H
#define MACROS_H

#include "msp430fr5739.h"
#include "adf4158.h"

// Typedef 
typedef unsigned short uint8;
typedef unsigned long uint32;

// IO 
#define GPIO_SEL0    0x00
#define GPIO_SEL1    0x00
#define GPIO_IN      0x00
#define GPIO_OUT     0xFF

// General
#define CLEAR_REG    0x00

// ADF4158
#define NUM_REGS     8


// Ports
#define CLOCK        0x09 // P1.0 & P1.3 - 0x01 + 0x08
#define DATA         0x12 // P1.1 & P1.4 - 0x02 + 0x10
#define LE           0x24 // P1.2 & P1.5 - 0x04 + 0x20

// Timers
#define TA0_FREQ     200 // Close-ish to 9600 baud (417)

#endif