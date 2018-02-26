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
#define INT          (uint32) 225       // Integer-N divisor
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
#define CLK1_DIV     (uint32) 251        // Divide by 12-bit for CLK1

// R3
#define NSEL         (uint32) 4095        // Divide by 12-bit for CLK1

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

#endif