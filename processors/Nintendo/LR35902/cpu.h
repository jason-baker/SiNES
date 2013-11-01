/*
 * Copyright 2013 Jason M. Baker
 */

#include "SiNES_types.h"

/**
 * A Logiucal representaiton of a LR35920 CPU.
 */
typedef struct _LR35920_CPU {
    /* Registers in the cpu */
    struct _REGISTERS {
        uint8   a;  // Accumulator register
        uint8   f;  // Flags register: Bits [ZNHC0000]
        uint8   b;  // b
        uint8   c;  // c
        uint8   d;  // d
        uint8   e;  // e
        uint8   h;  // h
        uint8   l;  // l

        uint16  sp; // Stack pointer
        uint16  pc; // Program Counter
    } r;
} LR35920_CPU;

