#ifndef COMMANDS_H
#define COMMANDS_H

#include "msp430fr5739.h"
#include "macros.h"

//------------------------------------------------------------------------------
// Function Declarations
    void clock_event(void);
    void bit_bang(void);
//------------------------------------------------------------------------------
    
//------------------------------------------------------------------------------
// Local Variable Declarations
    static uint8 clk_state = 0;
    static uint8 cur_bit = 0;
    static uint8 cur_reg = 0;
    static uint32 adf4158_cmds[] = {ADF4158_R7,
                                    ADF4158_R6,
                                    ADF4158_R5,
                                    ADF4158_R4,
                                    ADF4158_R3,
                                    ADF4158_R2,
                                    ADF4158_R1,
                                    ADF4158_R0
                                   };
//-----------------------------------------------------------------------------

#endif