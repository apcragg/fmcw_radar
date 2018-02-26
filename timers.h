#ifndef TIMERS_H
#define TIMERS_H

#include "msp430fr5739.h"
#include "macros.h"
#include "commands.h"
#include "globals.h"

//------------------------------------------------------------------------------
// Function Declarations
    void init_timers(void);
    uint8 has_clk_evt(void);
    void clear_clk_evt(void);
//------------------------------------------------------------------------------

#endif