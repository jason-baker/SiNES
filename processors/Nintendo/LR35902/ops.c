/*
 * Copyright 2013 Jason M. Baker
 */

#include "SiNES_types.h"
#include "ops.h"
#include "registers.h"

typedef void (*LR35902_OP_FN)();

#define PRE_OP_FUNC static void

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
/*          0x-0     0x-1       0x-2        0x-3        0x-4        0x-5        0x-6        0x-7        0x-8       0x-9        0x-A        0x-B        0x-C        0x-D        0x-E        0x-F */
/*0x1-*/    nop,     ld_bc_d16, NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0x2-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0x3-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0x4-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0x5-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0x6-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0x7-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0x8-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0x9-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0xA-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0xB-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0xC-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0xD-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0xE-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
/*0xF-*/    NULL,    NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,      NULL,       NULL,       NULL,       NULL,       NULL,       NULL,       NULL,
};

LR35902_OP_FN opCB[256] = {
    NULL
};

/**
 * Execute an operation.
 */
void exec_op(void)
{
    uint8 opcode = 0x00;//op_read(r.pc++);
    op[opcode]();
}

#undef DEF_OP
