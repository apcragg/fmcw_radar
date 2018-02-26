#ifndef ADF4158_H
#define ADF4158_H

// 0 is disable
// 1 is enable
// Unless otherwise explicitly stated

// Register Mapping
// General 
#define FRAC         0           // 25-bit fractional divder

#define NBITS_MASK(X)   ((0x00000001u << X) - 1)

// R0
#define MUXOUT       (uint32) 0xE        // RTFM
#define INT          (uint32) 225        // Integer-N divisor
#define FRAC_MSB     (uint32) 0          // 12-bit

// R1
#define FRAC_LSB     (uint32) 0          // 13-bit

// R2
#define CSR_EN       (uint32) 0          // Cycle Slip Reduction
#define CP_CURRENT   (uint32) 0xF        // Full scale is 0.31mA -> 5.0mA
#define PRESCALER    (uint32) 0          // RTFM
#define REF_HALF     (uint32) 0          // Halve incoming refrence signal
#define REF_X2       (uint32) 0          // Double incoming refrence signal
#define RDIV         (uint32) 16         // Divide R by
#define CLK1_DIV     (uint32) 251        // 12-bit clock 1 divisor word

// R3
#define NSEL         (uint32) 0          // RTFM
#define SD_RESET     (uint32) 0          // Delta-Sigma reset on write to R0
#define RAMP_MODE    (uint32) 0          // Generated ramp type
#define PSK_EN       (uint32) 0          // Phase-shift keying 
#define FSK_EN       (uint32) 0          // Frequency-shift keying
#define LPD          (uint32) 0          // Lock detect precision
#define PD_POLARITY  (uint32) 0          // Phase detector polarity
#define POWER_DN     (uint32) 0          // Programable power-down
#define CP_3S        (uint32) 0          // Charge pump 3 state
#define C_RESET      (uint32) 0          // RF counter reset

// R4
#define LE_SEL       (uint32) 0          // LE Syncronization
#define SD_MODE      (uint32) 0          // Sigma-delta modulator mode
#define NB_CURRENT   (uint32) 0          // Negative bleed current
#define RB_MUXOUT    (uint32) 0          // Readback to MUXOUT
#define CLK_DIVM     (uint32) 0          // Clock divider mode
#define CLK2_DIV     (uint32) 0          // S12-bit clock 2 divisor word

// R5
#define TX_CLK       (uint32) 0          // TX clock selection
#define PAR_RAMP     (uint32) 0          // Parabolic ramp
#define RB_INTERRUPT (uint32) 0          // Readback interrupt type
#define FSK_RAMP_EN  (uint32) 0          // FSK Ramp enable
#define RAMP2_EN     (uint32) 0          // Ramp 2 enable
#define DEV_SEL      (uint32) 0          // Deviation select
#define DEV_OFFSET   (uint32) 0          // 4-bit Deviation offset word
#define DEV_WORD     (uint32) 0          // 16-bit deviation word


// R6
#define STEP_SEL     (uint32) 0          // Step selection
#define STEP         (uint32) 1          // 20-bit step word

// R7
#define RAMPD_FL     (uint32) 0          // Rampdelay fast-lock
#define RAMPD        (uint32) 0          // Ramp delay
#define DELAY_CS     (uint32) 0          // Ramp delay clock-selet
#define DELAY_SE     (uint32) 0          // Delay start enable
#define DELAY        (uint32) 1          // 12-bit delay start word

// Register bitstream generartion
#define ADF4158_R0   (((NBITS_MASK(4) & MUXOUT) << 27) | \
                      ((NBITS_MASK(12) & INT) << 15) | \
                      ((NBITS_MASK(12) & FRAC_MSB) << 3) | \
                      ((NBITS_MASK(3) & 0x0) << 0) \
                     )

#define ADF4158_R1   (((NBITS_MASK(13) & FRAC_LSB) << 15) | \
                      ((NBITS_MASK(3) & 0x1) << 0) \
                     )

#define ADF4158_R2   (((NBITS_MASK(1) & CSR_EN) << 28) | \
                      ((NBITS_MASK(4) & CP_CURRENT) << 24) | \
                      ((NBITS_MASK(1) & PRESCALER) << 22) | \
                      ((NBITS_MASK(1) & REF_HALF) << 21) | \
                      ((NBITS_MASK(1) & REF_X2) << 20) | \
                      ((NBITS_MASK(5) & RDIV) << 15) | \
                      ((NBITS_MASK(12) & CLK1_DIV) << 3) | \
                      ((NBITS_MASK(3) & 0x2) << 0) \
                     )

#define ADF4158_R3   (((NBITS_MASK(1) & NSEL) << 15) | \
                      ((NBITS_MASK(1) & SD_RESET) << 14) | \
                      ((NBITS_MASK(2) & RAMP_MODE) << 10) | \
                      ((NBITS_MASK(1) & PSK_EN) << 9) | \
                      ((NBITS_MASK(1) & FSK_EN) << 8) | \
                      ((NBITS_MASK(1) & LPD) << 7) | \
                      ((NBITS_MASK(1) & LPD) << 6) | \
                      ((NBITS_MASK(1) & POWER_DN) << 5) | \
                      ((NBITS_MASK(1) & CP_3S) << 4) | \
                      ((NBITS_MASK(1) & C_RESET) << 3) | \
                      ((NBITS_MASK(3) & 0x3) << 0) \
                     )

#define ADF4158_R4   (((NBITS_MASK(1) & NSEL) << 31) | \
                      ((NBITS_MASK(5) & SD_RESET) << 26) | \
                      ((NBITS_MASK(2) & RAMP_MODE) << 23) | \
                      ((NBITS_MASK(2) & PSK_EN) << 21) | \
                      ((NBITS_MASK(2) & FSK_EN) << 19) | \
                      ((NBITS_MASK(12) & LPD) << 7) | \
                      ((NBITS_MASK(3) & 0x4) << 0) \
                     )

// Shift DEVIATION in parts because 16 bits is not < 16 bit system word
#define ADF4158_R5   (((NBITS_MASK(1) & NSEL) << 29) | \
                      ((NBITS_MASK(1) & SD_RESET) << 28) | \
                      ((NBITS_MASK(2) & RAMP_MODE) << 26) | \
                      ((NBITS_MASK(1) & PSK_EN) << 25) | \
                      ((NBITS_MASK(1) & FSK_EN) << 24) | \
                      ((NBITS_MASK(1) & LPD) << 23) | \
                      ((NBITS_MASK(4) & LPD) << 9) | \
                      ((NBITS_MASK(15) & (POWER_DN >> 1)) << 4) | \
                      ((NBITS_MASK(1) & POWER_DN) << 3) | \
                      ((NBITS_MASK(3) & 0x5) << 0) \
                     )

// Shift STEP in parts because 20 bits not < 16 bit system word
#define ADF4158_R6   (((NBITS_MASK(1) & STEP_SEL) << 23) | \
                      ((NBITS_MASK(15) & (STEP >> 5)) << 8) | \
                      ((NBITS_MASK(5) & STEP) << 3) | \
                      ((NBITS_MASK(3) & 0x6) << 0) \
                     )

#define ADF4158_R7   (((NBITS_MASK(1) & RAMPD_FL) << 18) | \
                      ((NBITS_MASK(1) & RAMPD) << 17) | \
                      ((NBITS_MASK(1) & DELAY_CS) << 16) | \
                      ((NBITS_MASK(1) & DELAY_SE) << 15) | \
                      ((NBITS_MASK(12) & DELAY) << 3) | \
                      ((NBITS_MASK(3) & 0x7) << 0) \
                     )

#endif