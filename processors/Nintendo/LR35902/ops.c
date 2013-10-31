/*
 * Copyright 2013 Jason M. Baker
 */

#include "SiNES_types.h"
#include "ops.hpp"
#include "registers.hpp"

typedef void (*LR35902_OP_FN)();

#define PRE_OP_FUNC static inline void

/*
FORMAT for processor operation functions.
<opcode> <mnemonic> [#1  #2] [Z H N C]
Where #1 is the length in bytes.
Where #2 is the duration in cycles.
Z,H,N,C are flags that were affected by the operation.
If the flag is marked by a "0" it is reset after instruction run.
If the flag is marked by a "1" it is set after instruction run.
If the flag is marked by a "-" it is unchanged.
If the flag is marked by the corresponding symbol it is affected by the function as normal.
Z - Zero Flag       : Set when a math operation is zero or two values match with CP.
H - Subtract Flag   : Set if the last operation used subtraction.
N - Half Carry Flag : If the lower nibble carried in the math operation.
C - Carry Flag      : Set if a carry occurred from the last math operation or register A is smaller in with CP.
*/

// 0x00     nop         [1  |  4] [- - - -]
PRE_OP_FUNC nop()
{}

// 0x01     ld_bc_d16   [3  | 12] [- - - -]
PRE_OP_FUNC ld_bc_d16()
{}

// 0x02     ld_de_d16   [1  |  8] [- - - -]
PRE_OP_FUNC ld_bc_a()
{}


LR35902_OP_FN op[256] = {
    nop,        // OP Code 0x00
    ld_bc_d16,  // OP Code 0x01
    NULL,       // OP Code 0x02
    NULL,       // OP Code 0x03
    NULL,       // OP Code 0x04
    NULL,       // OP Code 0x05
    NULL,       // OP Code 0x06
    NULL,       // OP Code 0x07
    NULL,       // OP Code 0x08
    NULL,       // OP Code 0x09
    NULL,       // OP Code 0x0A
    NULL,       // OP Code 0x0B
    NULL,       // OP Code 0x0C
    NULL,       // OP Code 0x0D
    NULL,       // OP Code 0x0E
    NULL,       // OP Code 0x0F
    NULL,       // OP Code 0x10
    NULL,       // OP Code 0x11
    NULL,       // OP Code 0x12
    NULL,       // OP Code 0x13
    NULL,       // OP Code 0x14
    NULL,       // OP Code 0x15
    NULL,       // OP Code 0x16
    NULL,       // OP Code 0x17
    NULL,       // OP Code 0x18
    NULL,       // OP Code 0x19
    NULL,       // OP Code 0x1A
    NULL,       // OP Code 0x1B
    NULL,       // OP Code 0x1C
    NULL,       // OP Code 0x1D
    NULL,       // OP Code 0x1E
    NULL,       // OP Code 0x1F
    NULL,       // OP Code 0x20
    NULL,       // OP Code 0x21
    NULL,       // OP Code 0x22
    NULL,       // OP Code 0x23
    NULL,       // OP Code 0x24
    NULL,       // OP Code 0x25
    NULL,       // OP Code 0x26
    NULL,       // OP Code 0x27
    NULL,       // OP Code 0x28
    NULL,       // OP Code 0x29
    NULL,       // OP Code 0x2A
    NULL,       // OP Code 0x2B
    NULL,       // OP Code 0x2C
    NULL,       // OP Code 0x2D
    NULL,       // OP Code 0x2E
    NULL,       // OP Code 0x2F
    NULL,       // OP Code 0x30
    NULL,       // OP Code 0x31
    NULL,       // OP Code 0x32
    NULL,       // OP Code 0x33
    NULL,       // OP Code 0x34
    NULL,       // OP Code 0x35
    NULL,       // OP Code 0x36
    NULL,       // OP Code 0x37
    NULL,       // OP Code 0x38
    NULL,       // OP Code 0x39
    NULL,       // OP Code 0x3A
    NULL,       // OP Code 0x3B
    NULL,       // OP Code 0x3C
    NULL,       // OP Code 0x3D
    NULL,       // OP Code 0x3E
    NULL,       // OP Code 0x3F
    NULL,       // OP Code 0x40
    NULL,       // OP Code 0x41
    NULL,       // OP Code 0x42
    NULL,       // OP Code 0x43
    NULL,       // OP Code 0x44
    NULL,       // OP Code 0x45
    NULL,       // OP Code 0x46
    NULL,       // OP Code 0x47
    NULL,       // OP Code 0x48
    NULL,       // OP Code 0x49
    NULL,       // OP Code 0x4A
    NULL,       // OP Code 0x4B
    NULL,       // OP Code 0x4C
    NULL,       // OP Code 0x4D
    NULL,       // OP Code 0x4E
    NULL,       // OP Code 0x4F
    NULL,       // OP Code 0x50
    NULL,       // OP Code 0x51
    NULL,       // OP Code 0x52
    NULL,       // OP Code 0x53
    NULL,       // OP Code 0x54
    NULL,       // OP Code 0x55
    NULL,       // OP Code 0x56
    NULL,       // OP Code 0x57
    NULL,       // OP Code 0x58
    NULL,       // OP Code 0x59
    NULL,       // OP Code 0x5A
    NULL,       // OP Code 0x5B
    NULL,       // OP Code 0x5C
    NULL,       // OP Code 0x5D
    NULL,       // OP Code 0x5E
    NULL,       // OP Code 0x5F
    NULL,       // OP Code 0x60
    NULL,       // OP Code 0x61
    NULL,       // OP Code 0x62
    NULL,       // OP Code 0x63
    NULL,       // OP Code 0x64
    NULL,       // OP Code 0x65
    NULL,       // OP Code 0x66
    NULL,       // OP Code 0x67
    NULL,       // OP Code 0x68
    NULL,       // OP Code 0x69
    NULL,       // OP Code 0x6A
    NULL,       // OP Code 0x6B
    NULL,       // OP Code 0x6C
    NULL,       // OP Code 0x6D
    NULL,       // OP Code 0x6E
    NULL,       // OP Code 0x6F
};

LR35902_OP_FN opCB[256] = {
};

/**
 * Execute an operation.
 */
void exec_op()
{
    uint8 opcode = 0x00;//op_read(r.pc++);
    op[opcode]();
}

#undef DEF_OP
