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
    static uint32 adf4158_cmds[] = {0x00000007u,
                                    0x00000006u,
                                    0x00000005u,
                                    0x00000004u,
                                    0x00000003u,
                                    ADF4158_R2,
                                    ADF4158_R1,
                                    ADF4158_R0
                                   };
//-----------------------------------------------------------------------------

#endif