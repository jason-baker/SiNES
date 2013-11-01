#include "SiNES_types.h"

typedef struct _REGISTERS {
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
} REGISTERS, * LPREGISTERS;
