/*
 * Copyright 2013 Jason M. Baker
 */

#include "SiNES_types.h"
#include "cpu.h"
#include "ops.h"

/**
 * Operation function pointer.
 */
typedef void (*LR35902_OP_FN)(LR35920_CPU *c);

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

#define PRE_OP_FUNC static void

/**
 * Convert 2 8 bit registers into a 16 bit register.
 */
#define GET_REG16(REG1, REG2) (((REG1) << 8) | (REG2))

/*********************************************************************************************************************\
| @TODO                                                                                                       |
\*********************************************************************************************************************/

// 0x00     nop         [1  |  4] [- - - -]
PRE_OP_FUNC nop(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
}

/*********************************************************************************************************************\
| Jump, Return, Call, Reset Commands                                                                                  |
\*********************************************************************************************************************/

// 0x20     jr_nz       [2  |12/8] [- - - -]
PRE_OP_FUNC jr_nz(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
    /* @TODO */
}

// 0x30     jr_nc       [2  |12/8] [- - - -]
PRE_OP_FUNC jr_nc(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
    /* @TODO */
}

// 0x18     jr          [2  | 12] [- - - -]
PRE_OP_FUNC jr(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
    /* @TODO */
}

// 0x28     jr_z        [2  |12/8] [- - - -]
PRE_OP_FUNC jr_z(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
    /* @TODO */
}

// 0x38     jr_c        [2  |12/8] [- - - -]
PRE_OP_FUNC jr_c(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
    /* @TODO */
}

// 0xC0     ret_nz      [1  |20/8] [- - - -]
PRE_OP_FUNC ret_nz(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
    /* @TODO */
}

// 0xD0     ret_nc      [1  |20/8] [- - - -]
PRE_OP_FUNC ret_nc(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
    /* @TODO */
}

// 0xC2     jp_nz      [3  |16/12] [- - - -]
PRE_OP_FUNC jp_nz(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
    /* @TODO */
}

// 0xD2     jp_nc      [3  |16/12] [- - - -]
PRE_OP_FUNC jp_nc(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
    /* @TODO */
}

// 0xC3     call_nz    [3  |24/12] [- - - -]
PRE_OP_FUNC call_nz(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
    /* @TODO */
}

// 0xD3     call_nc    [3  |24/12] [- - - -]
PRE_OP_FUNC call_nc(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
    /* @TODO */
}

/**
 * Define a function for pushing present address onto stack and jumping to offset
 * op_rst_nnh    [2  | 16] [- - - -]
 */
#define op_rst_nnh(OFFSET)                      \
PRE_OP_FUNC rst_##OFFSET##h(LR35920_CPU *c) {   \
    /* @TODO CLOCK HANDLING */                  \
    /*  */                                      \
}
op_rst_nnh(00)      /* OPCODE: 0xC7 */
op_rst_nnh(08)      /* OPCODE: 0xCF */
op_rst_nnh(10)      /* OPCODE: 0xD7 */
op_rst_nnh(18)      /* OPCODE: 0xCF */
op_rst_nnh(20)      /* OPCODE: 0xE7 */
op_rst_nnh(28)      /* OPCODE: 0xEF */
op_rst_nnh(30)      /* OPCODE: 0xF7 */
op_rst_nnh(38)      /* OPCODE: 0xFF */
#undef op_rst_nnh

/*********************************************************************************************************************\
| 8 Bit Load Commands                                                                                                 |
\*********************************************************************************************************************/

/**
 * Define a function for putting an immediate 8 bit value from the stack into a register.
 * op_ld_r_n    [2  |  8] [- - - -]
 */
#define op_ld_r_n(REG)                      \
PRE_OP_FUNC ld_##REG##_n(LR35920_CPU *c) { \
    /* @TODO CLOCK HANDLING */              \
    /* c->r.REG = c->mem_read((c->r.pc)++); */     \
}
op_ld_r_n(b)    /* OPCODE: 0x06 */
op_ld_r_n(c)    /* OPCODE: 0x0E */
op_ld_r_n(d)    /* OPCODE: 0x16 */
op_ld_r_n(e)    /* OPCODE: 0x1E */
op_ld_r_n(h)    /* OPCODE: 0x26 */
op_ld_r_n(l)    /* OPCODE: 0x2E */
op_ld_r_n(a)    /* OPCODE: 0x3E */
#undef op_ld_r_n

/**
 * Define a function for putting an immediate 8 bit value from the stack into a register.
 * op_ld_r_n    [1  |  8] [- - - -]
 */
#define op_ld_rr_a(REGH, REGL)                      \
PRE_OP_FUNC ld_##REGH##REGL##_a(LR35920_CPU *c) {   \
    /* @TODO CLOCK HANDLING */                      \
    /* c->r.a = c->mem_read(GET_REG16((c->r.REGH, c->r.REGL)); */     \
}
op_ld_rr_a(b,c)     /* OPCODE: 0x02 */
op_ld_rr_a(d,e)     /* OPCODE: 0x12 */
#undef op_ld_rr_a

/**
 * Define a function for putting an immediate 8 bit value from the stack into address at HL.
 * OPCODE: 0x36
 * ld_hl_n   [2  | 12] [- - - -]
 */
PRE_OP_FUNC ld_hl_n(LR35920_CPU *c) {
    /* @TODO CLOCK HANDLING */
    /* c->mem_write(GET_REG16((c->r.h, c->r.l), c->r.REG), c->mem_read((c->r.pc)++)); */
}

/**
 * Define a function for moving value in REG2 to REG1.
 * op_ld_r_r    [1  |  4] [- - - -]
 */
#define op_ld_r_r(REG1, REG2)                       \
PRE_OP_FUNC ld_##REG1##_##REG2(LR35920_CPU *c) {    \
    /* @TODO CLOCK HANDLING */                      \
    /* c->r.REG1 = c->r.REG2 */                          \
}
/* 0x4- OPCODES */
op_ld_r_r(b, b) /* OPCODE: 0x40 */
op_ld_r_r(b, c) /* OPCODE: 0x41 */
op_ld_r_r(b, d) /* OPCODE: 0x42 */
op_ld_r_r(b, e) /* OPCODE: 0x43 */
op_ld_r_r(b, h) /* OPCODE: 0x44 */
op_ld_r_r(b, l) /* OPCODE: 0x45 */
op_ld_r_r(b, a) /* OPCODE: 0x47 */
op_ld_r_r(c, b) /* OPCODE: 0x48 */
op_ld_r_r(c, c) /* OPCODE: 0x49 */
op_ld_r_r(c, d) /* OPCODE: 0x4A */
op_ld_r_r(c, e) /* OPCODE: 0x4B */
op_ld_r_r(c, h) /* OPCODE: 0x4C */
op_ld_r_r(c, l) /* OPCODE: 0x4D */
op_ld_r_r(c, a) /* OPCODE: 0x4F */
/* 0x5- OPCODES */
op_ld_r_r(d, b) /* OPCODE: 0x50 */
op_ld_r_r(d, c) /* OPCODE: 0x51 */
op_ld_r_r(d, d) /* OPCODE: 0x52 */
op_ld_r_r(d, e) /* OPCODE: 0x53 */
op_ld_r_r(d, h) /* OPCODE: 0x54 */
op_ld_r_r(d, l) /* OPCODE: 0x55 */
op_ld_r_r(d, a) /* OPCODE: 0x57 */
op_ld_r_r(e, b) /* OPCODE: 0x58 */
op_ld_r_r(e, c) /* OPCODE: 0x59 */
op_ld_r_r(e, d) /* OPCODE: 0x5A */
op_ld_r_r(e, e) /* OPCODE: 0x5B */
op_ld_r_r(e, h) /* OPCODE: 0x5C */
op_ld_r_r(e, l) /* OPCODE: 0x5D */
op_ld_r_r(e, a) /* OPCODE: 0x5F */
/* 0x6- OPCODES */
op_ld_r_r(h, b) /* OPCODE: 0x60 */
op_ld_r_r(h, c) /* OPCODE: 0x61 */
op_ld_r_r(h, d) /* OPCODE: 0x62 */
op_ld_r_r(h, e) /* OPCODE: 0x63 */
op_ld_r_r(h, h) /* OPCODE: 0x64 */
op_ld_r_r(h, l) /* OPCODE: 0x65 */
op_ld_r_r(h, a) /* OPCODE: 0x67 */
op_ld_r_r(l, b) /* OPCODE: 0x68 */
op_ld_r_r(l, c) /* OPCODE: 0x69 */
op_ld_r_r(l, d) /* OPCODE: 0x6A */
op_ld_r_r(l, e) /* OPCODE: 0x6B */
op_ld_r_r(l, h) /* OPCODE: 0x6C */
op_ld_r_r(l, l) /* OPCODE: 0x6D */
op_ld_r_r(l, a) /* OPCODE: 0x6F */
/* 0x7- OPCODES */
op_ld_r_r(a, b) /* OPCODE: 0x78 */
op_ld_r_r(a, c) /* OPCODE: 0x79 */
op_ld_r_r(a, d) /* OPCODE: 0x7A */
op_ld_r_r(a, e) /* OPCODE: 0x7B */
op_ld_r_r(a, h) /* OPCODE: 0x7C */
op_ld_r_r(a, l) /* OPCODE: 0x7D */
op_ld_r_r(a, a) /* OPCODE: 0x7F */
#undef op_ld_r_r

/**
 * Define a function for moving value from the address in HL to REG.
 * op_ld_r_hl  [1  |  8] [- - - -]
 */
#define op_ld_r_hl(REG)                         \
PRE_OP_FUNC ld_##REG##_hl(LR35920_CPU *c) {     \
    /* @TODO CLOCK HANDLING */                  \
    /* c->r.REG = c->mem_read(GET_REG16((c->r.h, c->r.l)) */  \
}
op_ld_r_hl(b)   /* OPCODE: 0x46 */
op_ld_r_hl(c)   /* OPCODE: 0x4E */
op_ld_r_hl(d)   /* OPCODE: 0x56 */
op_ld_r_hl(e)   /* OPCODE: 0x5E */
op_ld_r_hl(h)   /* OPCODE: 0x66 */
op_ld_r_hl(l)   /* OPCODE: 0x6E */
op_ld_r_hl(a)   /* OPCODE: 0x7E */
#undef op_ld_r_hl

/**
 * Define a function for moving value from REG into the address in HL.
 * op_ld_hl_r  [1  |  8] [- - - -]
 */
#define op_ld_hl_r(REG)                         \
PRE_OP_FUNC ld_hl_##REG(LR35920_CPU *c) {       \
    /* @TODO CLOCK HANDLING */                  \
    /* c->mem_write(GET_REG16((c->r.h, c->r.l), c->r.REG)) */  \
}
op_ld_hl_r(b)   /* OPCODE: 0x70 */
op_ld_hl_r(c)   /* OPCODE: 0x71 */
op_ld_hl_r(d)   /* OPCODE: 0x72 */
op_ld_hl_r(e)   /* OPCODE: 0x73 */
op_ld_hl_r(h)   /* OPCODE: 0x74 */
op_ld_hl_r(l)   /* OPCODE: 0x75 */
op_ld_hl_r(a)   /* OPCODE: 0x77 */
#undef op_ld_hl_r

/*********************************************************************************************************************\
| 8 Bit Arithmetic Commands                                                                                           |
\*********************************************************************************************************************/

/**
 * Define a function for decrementing a register.
 * op_ld_hl_r  [1  |  4] [Z 0 H -]
 */
#define op_inc_r(REG)                       \
PRE_OP_FUNC inc_##REG(LR35920_CPU *c) {     \
    /* @TODO CLOCK HANDLING */              \
    /* @TODO */  \
}
op_inc_r(b)     /* OPCODE: 0x04 */
op_inc_r(c)     /* OPCODE: 0x0C */
op_inc_r(d)     /* OPCODE: 0x14 */
op_inc_r(e)     /* OPCODE: 0x1C */
op_inc_r(h)     /* OPCODE: 0x24 */
op_inc_r(l)     /* OPCODE: 0x2C */
op_inc_r(a)     /* OPCODE: 0x3C */
#undef op_inc_r
/* @TODO HL*/

/**
 * Define a function for decrementing a register.
 * op_ld_hl_r  [1  |  4] [Z 1 H -]
 */
#define op_dec_r(REG)                       \
PRE_OP_FUNC dec_##REG(LR35920_CPU *c) {     \
    /* @TODO CLOCK HANDLING */              \
    /* @TODO */  \
}
op_dec_r(b)     /* OPCODE: 0x05 */
op_dec_r(c)     /* OPCODE: 0x0D */
op_dec_r(d)     /* OPCODE: 0x15 */
op_dec_r(e)     /* OPCODE: 0x1D */
op_dec_r(h)     /* OPCODE: 0x25 */
op_dec_r(l)     /* OPCODE: 0x2D */
op_dec_r(a)     /* OPCODE: 0x3D */
#undef op_dec_r
/* @TODO HL*/

/**
 * Define a function for adding a register to a.
 * op_ld_hl_r  [1  |  4] [Z 0 H C]
 */
#define op_add_a_r(REG)                     \
PRE_OP_FUNC add_a_##REG(LR35920_CPU *c) {   \
    /* @TODO CLOCK HANDLING */              \
    /* @TODO */  \
}
op_add_a_r(b)     /* OPCODE: 0x80 */
op_add_a_r(c)     /* OPCODE: 0x81 */
op_add_a_r(d)     /* OPCODE: 0x82 */
op_add_a_r(e)     /* OPCODE: 0x83 */
op_add_a_r(h)     /* OPCODE: 0x84 */
op_add_a_r(l)     /* OPCODE: 0x85 */
op_add_a_r(a)     /* OPCODE: 0x87 */
#undef op_add_a_r
/* @TODO HL & n*/

/**
 * Define a function for adding a register value with carry flag to A.
 * op_ld_hl_r  [1  |  4] [Z 0 H C]
 */
#define op_adc_a_r(REG)                     \
PRE_OP_FUNC adc_a_##REG(LR35920_CPU *c) {   \
    /* @TODO CLOCK HANDLING */              \
    /* @TODO */  \
}
op_adc_a_r(b)     /* OPCODE: 0x88 */
op_adc_a_r(c)     /* OPCODE: 0x89 */
op_adc_a_r(d)     /* OPCODE: 0x8A */
op_adc_a_r(e)     /* OPCODE: 0x8B */
op_adc_a_r(h)     /* OPCODE: 0x8C */
op_adc_a_r(l)     /* OPCODE: 0x8D */
op_adc_a_r(a)     /* OPCODE: 0x8F */
#undef op_adc_a_r
/* @TODO HL & n*/

/**
 * Define a function for adding a register to a.
 * op_ld_hl_r  [1  |  4] [Z 0 H C]
 */
#define op_sub_r(REG)                       \
PRE_OP_FUNC sub_##REG(LR35920_CPU *c) {     \
    /* @TODO CLOCK HANDLING */              \
    /* @TODO */  \
}
op_sub_r(b)     /* OPCODE: 0x90 */
op_sub_r(c)     /* OPCODE: 0x91 */
op_sub_r(d)     /* OPCODE: 0x92 */
op_sub_r(e)     /* OPCODE: 0x93 */
op_sub_r(h)     /* OPCODE: 0x94 */
op_sub_r(l)     /* OPCODE: 0x95 */
op_sub_r(a)     /* OPCODE: 0x97 */
#undef op_sub_r
/* @TODO HL & n*/

/**
 * Define a function for subtracting with carry from register to a.
 * op_sbc_r  [1  |  4] [Z 0 H C]
 */
#define op_sbc_r(REG)                       \
PRE_OP_FUNC sbc_##REG(LR35920_CPU *c) {     \
    /* @TODO CLOCK HANDLING */              \
    /* @TODO */  \
}
op_sbc_r(b)     /* OPCODE: 0x98 */
op_sbc_r(c)     /* OPCODE: 0x99 */
op_sbc_r(d)     /* OPCODE: 0x9A */
op_sbc_r(e)     /* OPCODE: 0x9B */
op_sbc_r(h)     /* OPCODE: 0x9C */
op_sbc_r(l)     /* OPCODE: 0x9D */
op_sbc_r(a)     /* OPCODE: 0x9F */
#undef op_sbc_r
/* @TODO HL & n*/

/**
 * Define a function for and'ing a register to a.
 * op_ld_hl_r  [1  |  4] [Z 0 1 0]
 */
#define op_and_r(REG)                       \
PRE_OP_FUNC and_##REG(LR35920_CPU *c) {     \
    /* @TODO CLOCK HANDLING */              \
    /* @TODO */  \
}
op_and_r(b)     /* OPCODE: 0xA0 */
op_and_r(c)     /* OPCODE: 0xA1 */
op_and_r(d)     /* OPCODE: 0xA2 */
op_and_r(e)     /* OPCODE: 0xA3 */
op_and_r(h)     /* OPCODE: 0xA4 */
op_and_r(l)     /* OPCODE: 0xA5 */
op_and_r(a)     /* OPCODE: 0xA7 */
#undef op_and_r
/* @TODO HL & n*/

/**
 * Define a function for adding a register to a.
 * op_and_r  [1  |  4] [Z 0 0 0]
 */
#define op_xor_r(REG)                       \
PRE_OP_FUNC xor_##REG(LR35920_CPU *c) {     \
    /* @TODO CLOCK HANDLING */              \
    /* @TODO */  \
}
op_xor_r(b)     /* OPCODE: 0xA8 */
op_xor_r(c)     /* OPCODE: 0xA9 */
op_xor_r(d)     /* OPCODE: 0xAA */
op_xor_r(e)     /* OPCODE: 0xAB */
op_xor_r(h)     /* OPCODE: 0xAC */
op_xor_r(l)     /* OPCODE: 0xAD */
op_xor_r(a)     /* OPCODE: 0xAF */
#undef op_xor_r
/* @TODO HL & n*/

/**
 * Define a function for or'ing a register to a.
 * op_ld_hl_r  [1  |  4] [Z 0 0 0]
 */
#define op_or_r(REG)                        \
PRE_OP_FUNC or_##REG(LR35920_CPU *c) {      \
    /* @TODO CLOCK HANDLING */              \
    /* @TODO */  \
}
op_or_r(b)      /* OPCODE: 0xB0 */
op_or_r(c)      /* OPCODE: 0xB1 */
op_or_r(d)      /* OPCODE: 0xB2 */
op_or_r(e)      /* OPCODE: 0xB3 */
op_or_r(h)      /* OPCODE: 0xB4 */
op_or_r(l)      /* OPCODE: 0xB5 */
op_or_r(a)      /* OPCODE: 0xB7 */
#undef op_or_r
/* @TODO HL & n*/

/**
 * Define a function for adding a register to a.
 * op_and_r  [1  |  4] [Z 1 H C]
 */
#define op_cp_r(REG)                        \
PRE_OP_FUNC cp_##REG(LR35920_CPU *c) {      \
    /* @TODO CLOCK HANDLING */              \
    /* @TODO */  \
}
op_cp_r(b)      /* OPCODE: 0xB8 */
op_cp_r(c)      /* OPCODE: 0xB9 */
op_cp_r(d)      /* OPCODE: 0xBA */
op_cp_r(e)      /* OPCODE: 0xBB */
op_cp_r(h)      /* OPCODE: 0xBC */
op_cp_r(l)      /* OPCODE: 0xBD */
op_cp_r(a)      /* OPCODE: 0xBF */
#undef op_cp_r
/* @TODO HL & n*/

/*********************************************************************************************************************\
| 16 Bit Load Commands                                                                                                |
\*********************************************************************************************************************/

/**
 * Define a function for putting an immediate 16 bit value from the stack into 2 8 bit registers.
 * op_ld_rr_nn  [1  |  8] [- - - -]
 */
#define op_ld_rr_nn(REGH, REGL)                     \
PRE_OP_FUNC ld_##REGH##REGL##_nn(LR35920_CPU *c) {  \
    /* @TODO CLOCK HANDLING */                      \
    /* c->r.REGL = c->mem_read((c->r.pc)++) */      \
    /* c->r.REGH = c->mem_read((c->r.pc)++) */      \
}
op_ld_rr_nn(b,c)   /* OPCODE: 0x01 */
op_ld_rr_nn(d,e)   /* OPCODE: 0x11 */
op_ld_rr_nn(h,l)   /* OPCODE: 0x21 */
#undef op_ld_rr_nn
/* @TODO SP */

/*********************************************************************************************************************\
| 16 Bit Arithmetic Commands                                                                                          |
\*********************************************************************************************************************/

/**
 * Define a function for decrementing a 16 bit register composed of 2 8 bit registers.
 * op_ld_hl_r  [1  |  8] [- - - -]
 */
#define op_inc_rr(REGH, REGL)                   \
PRE_OP_FUNC inc_##REGH##REGL(LR35920_CPU *c) {  \
    /* @TODO CLOCK HANDLING */                  \
    /* @TODO */  \
}
op_inc_rr(b,c)      /* OPCODE: 0x03 */
op_inc_rr(d,e)      /* OPCODE: 0x13 */
op_inc_rr(h,l)      /* OPCODE: 0x23 */
#undef op_inc_rr
/* @TODO SP */

/**
 * Define a function for incrementing a 16 bit register composed of 2 8 bit registers.
 * op_ld_hl_r  [1  |  8] [- - - -]
 */
#define op_dec_rr(REGH, REGL)                   \
PRE_OP_FUNC dec_##REGH##REGL(LR35920_CPU *c) {  \
    /* @TODO CLOCK HANDLING */                  \
    /* @TODO */  \
}
op_dec_rr(b,c)      /* OPCODE: 0x0B */
op_dec_rr(d,e)      /* OPCODE: 0x1B */
op_dec_rr(h,l)      /* OPCODE: 0x2B */
#undef op_dec_rr
/* @TODO SP */

/*********************************************************************************************************************\
| CBX Commands                                                                                                        |
\*********************************************************************************************************************/

/**
 * Define a function for rotating left bit 7 to carry.
 * op_rlc_r     [2  |  8] [Z 0 0 C]
 */
#define op_rlc_r(REG)                           \
PRE_OP_FUNC rlc_##REG(LR35920_CPU *c) {         \
    /* @TODO Clock Handling */                  \
    /* @TODO */                                 \
}
op_rlc_r(b);        /* CB OPCODE: 0x00 */
op_rlc_r(c);        /* CB OPCODE: 0x01 */
op_rlc_r(d);        /* CB OPCODE: 0x02 */
op_rlc_r(e);        /* CB OPCODE: 0x03 */
op_rlc_r(h);        /* CB OPCODE: 0x04 */
op_rlc_r(l);        /* CB OPCODE: 0x05 */
op_rlc_r(a);        /* CB OPCODE: 0x07 */
#undef op_rlc_r

/* @TODO rlc HL*/

/**
 * Define a function for rotating right bit 7 to carry.
 * op_rrc_r     [2  |  8] [Z 0 0 C]
 */
#define op_rrc_r(REG)                           \
PRE_OP_FUNC rrc_##REG(LR35920_CPU *c) {         \
    /* @TODO Clock Handling */                  \
    /* @TODO */                                 \
}
op_rrc_r(b);        /* CB OPCODE: 0x08 */
op_rrc_r(c);        /* CB OPCODE: 0x09 */
op_rrc_r(d);        /* CB OPCODE: 0x0A */
op_rrc_r(e);        /* CB OPCODE: 0x0B */
op_rrc_r(h);        /* CB OPCODE: 0x0C */
op_rrc_r(l);        /* CB OPCODE: 0x0D */
op_rrc_r(a);        /* CB OPCODE: 0x0F */
#undef op_rrc_r

/* @TODO rlc HL*/

/**
 * Define a function for rotating left through carry.
 * op_rl_r      [2  |  8] [Z 0 0 C]
 */
#define op_rl_r(REG)                            \
PRE_OP_FUNC rl_##REG(LR35920_CPU *c) {          \
    /* @TODO Clock Handling */                  \
    /* @TODO */                                 \
}
op_rl_r(b);         /* CB OPCODE: 0x10 */
op_rl_r(c);         /* CB OPCODE: 0x11 */
op_rl_r(d);         /* CB OPCODE: 0x12 */
op_rl_r(e);         /* CB OPCODE: 0x13 */
op_rl_r(h);         /* CB OPCODE: 0x14 */
op_rl_r(l);         /* CB OPCODE: 0x15 */
op_rl_r(a);         /* CB OPCODE: 0x17 */
#undef op_rl_r

/* @TODO rlc HL*/

/**
 * Define a function for rotating right through carry.
 * op_rr_r      [2  |  8] [Z 0 0 C]
 */
#define op_rr_r(REG)                            \
PRE_OP_FUNC rr_##REG(LR35920_CPU *c) {          \
    /* @TODO Clock Handling */                  \
    /* @TODO */                                 \
}
op_rr_r(b);         /* CB OPCODE: 0x18 */
op_rr_r(c);         /* CB OPCODE: 0x19 */
op_rr_r(d);         /* CB OPCODE: 0x1A */
op_rr_r(e);         /* CB OPCODE: 0x1B */
op_rr_r(h);         /* CB OPCODE: 0x1C */
op_rr_r(l);         /* CB OPCODE: 0x1D */
op_rr_r(a);         /* CB OPCODE: 0x1F */
#undef op_rr_r

/* @TODO rlc HL*/

/**
 * Define a function for shifting left into carry.
 * op_rlc_r     [2  |  8] [Z 0 0 C]
 */
#define op_sla_r(REG)                           \
PRE_OP_FUNC sla_##REG(LR35920_CPU *c) {         \
    /* @TODO Clock Handling */                  \
    /* @TODO */                                 \
}
op_sla_r(b);        /* CB OPCODE: 0x20 */
op_sla_r(c);        /* CB OPCODE: 0x21 */
op_sla_r(d);        /* CB OPCODE: 0x22 */
op_sla_r(e);        /* CB OPCODE: 0x23 */
op_sla_r(h);        /* CB OPCODE: 0x24 */
op_sla_r(l);        /* CB OPCODE: 0x25 */
op_sla_r(a);        /* CB OPCODE: 0x27 */
#undef op_sla_r

/* @TODO rlc HL*/

/**
 * Define a function for shifting right from carry.
 * op_sra_r     [2  |  8] [Z 0 0 C]
 */
#define op_sra_r(REG)                           \
PRE_OP_FUNC sra_##REG(LR35920_CPU *c) {         \
    /* @TODO Clock Handling */                  \
    /* @TODO */                                 \
}
op_sra_r(b);        /* CB OPCODE: 0x28 */
op_sra_r(c);        /* CB OPCODE: 0x29 */
op_sra_r(d);        /* CB OPCODE: 0x2A */
op_sra_r(e);        /* CB OPCODE: 0x2B */
op_sra_r(h);        /* CB OPCODE: 0x2C */
op_sra_r(l);        /* CB OPCODE: 0x2D */
op_sra_r(a);        /* CB OPCODE: 0x2F */
#undef op_sra_r

/* @TODO rlc HL*/

/**
 * Define a function for @TODO.
 * op_swap_r     [2  |  8] [Z 0 0 0]
 */
#define op_swap_r(REG)                          \
PRE_OP_FUNC swap_##REG(LR35920_CPU *c) {        \
    /* @TODO Clock Handling */                  \
    /* @TODO */                                 \
}
op_swap_r(b);       /* CB OPCODE: 0x30 */
op_swap_r(c);       /* CB OPCODE: 0x31 */
op_swap_r(d);       /* CB OPCODE: 0x32 */
op_swap_r(e);       /* CB OPCODE: 0x33 */
op_swap_r(h);       /* CB OPCODE: 0x34 */
op_swap_r(l);       /* CB OPCODE: 0x35 */
op_swap_r(a);       /* CB OPCODE: 0x37 */
#undef op_swap_r

/* @TODO swap HL*/

/**
 * Define a function for shifting right into carry MSB 0.
 * op_srl_r     [2  |  8] [Z 0 0 C]
 */
#define op_srl_r(REG)                           \
PRE_OP_FUNC srl_##REG(LR35920_CPU *c) {         \
    /* @TODO Clock Handling */                  \
    /* @TODO */                                 \
}
op_srl_r(b);        /* CB OPCODE: 0x38 */
op_srl_r(c);        /* CB OPCODE: 0x39 */
op_srl_r(d);        /* CB OPCODE: 0x3A */
op_srl_r(e);        /* CB OPCODE: 0x3B */
op_srl_r(h);        /* CB OPCODE: 0x3C */
op_srl_r(l);        /* CB OPCODE: 0x3D */
op_srl_r(a);        /* CB OPCODE: 0x3F */
#undef op_srl_r

/* @TODO srl hl */

/**
 * Define a function for shift right .
 * op_ld_hl_r  [2  |  8] [Z 0 1 -]
 */
#define op_bit_n_r(BIT, REG)                    \
PRE_OP_FUNC bit_##BIT##_##REG(LR35920_CPU *c) { \
    /* @TODO Clock Handling */                  \
    /* @TODO */                                 \
}
/* 0x4- CB OPCODES */
op_bit_n_r(0,b)     /* CB OPCODE: 0x40 */
op_bit_n_r(0,c)     /* CB OPCODE: 0x41 */
op_bit_n_r(0,d)     /* CB OPCODE: 0x42 */
op_bit_n_r(0,e)     /* CB OPCODE: 0x43 */
op_bit_n_r(0,h)     /* CB OPCODE: 0x44 */
op_bit_n_r(0,l)     /* CB OPCODE: 0x45 */
op_bit_n_r(0,a)     /* CB OPCODE: 0x47 */
op_bit_n_r(1,b)     /* CB OPCODE: 0x48 */
op_bit_n_r(1,c)     /* CB OPCODE: 0x49 */
op_bit_n_r(1,d)     /* CB OPCODE: 0x4A */
op_bit_n_r(1,e)     /* CB OPCODE: 0x4B */
op_bit_n_r(1,h)     /* CB OPCODE: 0x4C */
op_bit_n_r(1,l)     /* CB OPCODE: 0x4D */
op_bit_n_r(1,a)     /* CB OPCODE: 0x4F */
/* 0x5- CB OPCODES */
op_bit_n_r(2,b)     /* CB OPCODE: 0x50 */
op_bit_n_r(2,c)     /* CB OPCODE: 0x51 */
op_bit_n_r(2,d)     /* CB OPCODE: 0x52 */
op_bit_n_r(2,e)     /* CB OPCODE: 0x53 */
op_bit_n_r(2,h)     /* CB OPCODE: 0x54 */
op_bit_n_r(2,l)     /* CB OPCODE: 0x55 */
op_bit_n_r(2,a)     /* CB OPCODE: 0x57 */
op_bit_n_r(3,b)     /* CB OPCODE: 0x58 */
op_bit_n_r(3,c)     /* CB OPCODE: 0x59 */
op_bit_n_r(3,d)     /* CB OPCODE: 0x5A */
op_bit_n_r(3,e)     /* CB OPCODE: 0x5B */
op_bit_n_r(3,h)     /* CB OPCODE: 0x5C */
op_bit_n_r(3,l)     /* CB OPCODE: 0x5D */
op_bit_n_r(3,a)     /* CB OPCODE: 0x5F */
/* 0x6- CB OPCODES */
op_bit_n_r(4,b)     /* CB OPCODE: 0x60 */
op_bit_n_r(4,c)     /* CB OPCODE: 0x61 */
op_bit_n_r(4,d)     /* CB OPCODE: 0x62 */
op_bit_n_r(4,e)     /* CB OPCODE: 0x63 */
op_bit_n_r(4,h)     /* CB OPCODE: 0x64 */
op_bit_n_r(4,l)     /* CB OPCODE: 0x65 */
op_bit_n_r(4,a)     /* CB OPCODE: 0x67 */
op_bit_n_r(5,b)     /* CB OPCODE: 0x68 */
op_bit_n_r(5,c)     /* CB OPCODE: 0x69 */
op_bit_n_r(5,d)     /* CB OPCODE: 0x6A */
op_bit_n_r(5,e)     /* CB OPCODE: 0x6B */
op_bit_n_r(5,h)     /* CB OPCODE: 0x6C */
op_bit_n_r(5,l)     /* CB OPCODE: 0x6D */
op_bit_n_r(5,a)     /* CB OPCODE: 0x6F */
/* 0x7- CB OPCODES */
op_bit_n_r(6,b)     /* CB OPCODE: 0x70 */
op_bit_n_r(6,c)     /* CB OPCODE: 0x71 */
op_bit_n_r(6,d)     /* CB OPCODE: 0x72 */
op_bit_n_r(6,e)     /* CB OPCODE: 0x73 */
op_bit_n_r(6,h)     /* CB OPCODE: 0x74 */
op_bit_n_r(6,l)     /* CB OPCODE: 0x75 */
op_bit_n_r(6,a)     /* CB OPCODE: 0x77 */
op_bit_n_r(7,b)     /* CB OPCODE: 0x78 */
op_bit_n_r(7,c)     /* CB OPCODE: 0x79 */
op_bit_n_r(7,d)     /* CB OPCODE: 0x7A */
op_bit_n_r(7,e)     /* CB OPCODE: 0x7B */
op_bit_n_r(7,h)     /* CB OPCODE: 0x7C */
op_bit_n_r(7,l)     /* CB OPCODE: 0x7D */
op_bit_n_r(7,a)     /* CB OPCODE: 0x7F */
#undef op_bit_n_r

/* @TODO bit HL*/

/**
 * Define a function for resetting a specific bit in a register.
 * op_res_n_r  [2  |  8] [- - - -]
 */
#define op_res_n_r(BIT, REG)                    \
PRE_OP_FUNC res_##BIT##_##REG(LR35920_CPU *c) { \
    /* @TODO Clock Handling */                  \
    /* @TODO */                                 \
}
/* 0x8- CB OPCODES */
op_res_n_r(0,b)     /* CB OPCODE: 0x80 */
op_res_n_r(0,c)     /* CB OPCODE: 0x81 */
op_res_n_r(0,d)     /* CB OPCODE: 0x82 */
op_res_n_r(0,e)     /* CB OPCODE: 0x83 */
op_res_n_r(0,h)     /* CB OPCODE: 0x84 */
op_res_n_r(0,l)     /* CB OPCODE: 0x85 */
op_res_n_r(0,a)     /* CB OPCODE: 0x87 */
op_res_n_r(1,b)     /* CB OPCODE: 0x88 */
op_res_n_r(1,c)     /* CB OPCODE: 0x89 */
op_res_n_r(1,d)     /* CB OPCODE: 0x8A */
op_res_n_r(1,e)     /* CB OPCODE: 0x8B */
op_res_n_r(1,h)     /* CB OPCODE: 0x8C */
op_res_n_r(1,l)     /* CB OPCODE: 0x8D */
op_res_n_r(1,a)     /* CB OPCODE: 0x8F */
/* 0x9- CB OPCODES */
op_res_n_r(2,b)     /* CB OPCODE: 0x80 */
op_res_n_r(2,c)     /* CB OPCODE: 0x81 */
op_res_n_r(2,d)     /* CB OPCODE: 0x82 */
op_res_n_r(2,e)     /* CB OPCODE: 0x83 */
op_res_n_r(2,h)     /* CB OPCODE: 0x84 */
op_res_n_r(2,l)     /* CB OPCODE: 0x85 */
op_res_n_r(2,a)     /* CB OPCODE: 0x87 */
op_res_n_r(3,b)     /* CB OPCODE: 0x88 */
op_res_n_r(3,c)     /* CB OPCODE: 0x89 */
op_res_n_r(3,d)     /* CB OPCODE: 0x8A */
op_res_n_r(3,e)     /* CB OPCODE: 0x8B */
op_res_n_r(3,h)     /* CB OPCODE: 0x8C */
op_res_n_r(3,l)     /* CB OPCODE: 0x8D */
op_res_n_r(3,a)     /* CB OPCODE: 0x8F */
/* 0xA- CB OPCODES */
op_res_n_r(4,b)     /* CB OPCODE: 0xA0 */
op_res_n_r(4,c)     /* CB OPCODE: 0xA1 */
op_res_n_r(4,d)     /* CB OPCODE: 0xA2 */
op_res_n_r(4,e)     /* CB OPCODE: 0xA3 */
op_res_n_r(4,h)     /* CB OPCODE: 0xA4 */
op_res_n_r(4,l)     /* CB OPCODE: 0xA5 */
op_res_n_r(4,a)     /* CB OPCODE: 0xA7 */
op_res_n_r(5,b)     /* CB OPCODE: 0xA8 */
op_res_n_r(5,c)     /* CB OPCODE: 0xA9 */
op_res_n_r(5,d)     /* CB OPCODE: 0xAA */
op_res_n_r(5,e)     /* CB OPCODE: 0xAB */
op_res_n_r(5,h)     /* CB OPCODE: 0xAC */
op_res_n_r(5,l)     /* CB OPCODE: 0xAD */
op_res_n_r(5,a)     /* CB OPCODE: 0xAF */
/* 0xB- CB OPCODES */
op_res_n_r(6,b)     /* CB OPCODE: 0xB0 */
op_res_n_r(6,c)     /* CB OPCODE: 0xB1 */
op_res_n_r(6,d)     /* CB OPCODE: 0xB2 */
op_res_n_r(6,e)     /* CB OPCODE: 0xB3 */
op_res_n_r(6,h)     /* CB OPCODE: 0xB4 */
op_res_n_r(6,l)     /* CB OPCODE: 0xB5 */
op_res_n_r(6,a)     /* CB OPCODE: 0xB7 */
op_res_n_r(7,b)     /* CB OPCODE: 0xB8 */
op_res_n_r(7,c)     /* CB OPCODE: 0xB9 */
op_res_n_r(7,d)     /* CB OPCODE: 0xBA */
op_res_n_r(7,e)     /* CB OPCODE: 0xBB */
op_res_n_r(7,h)     /* CB OPCODE: 0xBC */
op_res_n_r(7,l)     /* CB OPCODE: 0xBD */
op_res_n_r(7,a)     /* CB OPCODE: 0xBF */
#undef op_res_n_r

/* @TODO RES HL */

/**
 * Define a function for setting a specific bit in a register.
 * op_set_n_r  [2  |  8] [- - - -]
 */
#define op_set_n_r(BIT, REG)                    \
PRE_OP_FUNC set_##BIT##_##REG(LR35920_CPU *c) { \
    /* @TODO Clock Handling */                  \
    /* @TODO */                                 \
}
/* 0xC- CB OPCODES */
op_set_n_r(0,b)     /* CB OPCODE: 0xC0 */
op_set_n_r(0,c)     /* CB OPCODE: 0xC1 */
op_set_n_r(0,d)     /* CB OPCODE: 0xC2 */
op_set_n_r(0,e)     /* CB OPCODE: 0xC3 */
op_set_n_r(0,h)     /* CB OPCODE: 0xC4 */
op_set_n_r(0,l)     /* CB OPCODE: 0xC5 */
op_set_n_r(0,a)     /* CB OPCODE: 0xC7 */
op_set_n_r(1,b)     /* CB OPCODE: 0xC8 */
op_set_n_r(1,c)     /* CB OPCODE: 0xC9 */
op_set_n_r(1,d)     /* CB OPCODE: 0xCA */
op_set_n_r(1,e)     /* CB OPCODE: 0xCB */
op_set_n_r(1,h)     /* CB OPCODE: 0xCC */
op_set_n_r(1,l)     /* CB OPCODE: 0xCD */
op_set_n_r(1,a)     /* CB OPCODE: 0xCF */
/* 0xD- CB OPCODES */
op_set_n_r(2,b)     /* CB OPCODE: 0xD0 */
op_set_n_r(2,c)     /* CB OPCODE: 0xD1 */
op_set_n_r(2,d)     /* CB OPCODE: 0xD2 */
op_set_n_r(2,e)     /* CB OPCODE: 0xD3 */
op_set_n_r(2,h)     /* CB OPCODE: 0xD4 */
op_set_n_r(2,l)     /* CB OPCODE: 0xD5 */
op_set_n_r(2,a)     /* CB OPCODE: 0xD7 */
op_set_n_r(3,b)     /* CB OPCODE: 0xD8 */
op_set_n_r(3,c)     /* CB OPCODE: 0xD9 */
op_set_n_r(3,d)     /* CB OPCODE: 0xDA */
op_set_n_r(3,e)     /* CB OPCODE: 0xDB */
op_set_n_r(3,h)     /* CB OPCODE: 0xDC */
op_set_n_r(3,l)     /* CB OPCODE: 0xDD */
op_set_n_r(3,a)     /* CB OPCODE: 0xDF */
/* 0xE- CB OPCODES */
op_set_n_r(4,b)     /* CB OPCODE: 0xE0 */
op_set_n_r(4,c)     /* CB OPCODE: 0xE1 */
op_set_n_r(4,d)     /* CB OPCODE: 0xE2 */
op_set_n_r(4,e)     /* CB OPCODE: 0xE3 */
op_set_n_r(4,h)     /* CB OPCODE: 0xE4 */
op_set_n_r(4,l)     /* CB OPCODE: 0xE5 */
op_set_n_r(4,a)     /* CB OPCODE: 0xE7 */
op_set_n_r(5,b)     /* CB OPCODE: 0xE8 */
op_set_n_r(5,c)     /* CB OPCODE: 0xE9 */
op_set_n_r(5,d)     /* CB OPCODE: 0xEA */
op_set_n_r(5,e)     /* CB OPCODE: 0xEB */
op_set_n_r(5,h)     /* CB OPCODE: 0xEC */
op_set_n_r(5,l)     /* CB OPCODE: 0xED */
op_set_n_r(5,a)     /* CB OPCODE: 0xEF */
/* 0xF- CB OPCODES */
op_set_n_r(6,b)     /* CB OPCODE: 0xF0 */
op_set_n_r(6,c)     /* CB OPCODE: 0xF1 */
op_set_n_r(6,d)     /* CB OPCODE: 0xF2 */
op_set_n_r(6,e)     /* CB OPCODE: 0xF3 */
op_set_n_r(6,h)     /* CB OPCODE: 0xF4 */
op_set_n_r(6,l)     /* CB OPCODE: 0xF5 */
op_set_n_r(6,a)     /* CB OPCODE: 0xF7 */
op_set_n_r(7,b)     /* CB OPCODE: 0xF8 */
op_set_n_r(7,c)     /* CB OPCODE: 0xF9 */
op_set_n_r(7,d)     /* CB OPCODE: 0xFA */
op_set_n_r(7,e)     /* CB OPCODE: 0xFB */
op_set_n_r(7,h)     /* CB OPCODE: 0xFC */
op_set_n_r(7,l)     /* CB OPCODE: 0xFD */
op_set_n_r(7,a)     /* CB OPCODE: 0xFF */
#undef op_set_n_r

/* @TODO set HL */

#undef PRE_OP_FUNC

LR35902_OP_FN op[256] = {
/*          0x-0        0x-1        0x-2        0x-3        0x-4        0x-5        0x-6        0x-7        0x-8        0x-9        0x-A        0x-B        0x-C        0x-D        0x-E        0x-F */
/*0x0-*/    nop,        ld_bc_nn,   ld_bc_a,    inc_bc,     inc_b,      dec_b,      ld_b_n,     rlca,       ld_nn_sp,   add_hl_bc,  ld_a_bc,    dec_bc,     inc_c,      dec_c,      ld_c_n,     rrca,
/*0x1-*/    stop,       ld_de_nn,   ld_de_a,    inc_de,     inc_d,      dec_d,      ld_d_n,     rla,        jr,         add_hl_de,  ld_a_de,    dec_de,     inc_e,      dec_e,      ld_e_n,     rra,
/*0x2-*/    jr_nz,      ld_hl_nn,   ldi_hl_a,   inc_hl,     inc_h,      dec_h,      ld_h_n,     daa,        jr_z,       add_hl_hl,  ldi_a_hl,   dec_hl,     inc_l,      dec_l,      ld_l_n,     cpl,
/*0x3-*/    jr_nc,      ld_sp_nn,   ldd_hl_a,   inc_sp,     inc_hl,     dec_hl,     ld_hl_n,    scf,        jr_c,       add_hl_sp,  ldd_a_hl,   dec_sp,     inc_a,      dec_a,      ld_a_n,     ccf,
/*0x4-*/    ld_b_b,     ld_b_c,     ld_b_d,     ld_b_e,     ld_b_h,     ld_b_l,     ld_b_hl,    ld_b_a,     ld_c_b,     ld_c_c,     ld_c_d,     ld_c_e,     ld_c_h,     ld_c_l,     ld_c_hl,    ld_c_a,
/*0x5-*/    ld_d_b,     ld_d_c,     ld_d_d,     ld_d_e,     ld_d_h,     ld_d_l,     ld_d_hl,    ld_d_a,     ld_e_b,     ld_e_c,     ld_e_d,     ld_e_e,     ld_e_h,     ld_e_l,     ld_e_hl,    ld_e_a,
/*0x6-*/    ld_h_b,     ld_h_c,     ld_h_d,     ld_h_e,     ld_h_h,     ld_h_l,     ld_h_hl,    ld_h_a,     ld_l_b,     ld_l_c,     ld_l_d,     ld_l_e,     ld_l_h,     ld_l_l,     ld_l_hl,    ld_l_a,
/*0x7-*/    ld_hl_b,    ld_hl_c,    ld_hl_d,    ld_hl_e,    ld_hl_h,    ld_hl_l,    halt,       ld_hl_a,    ld_a_b,     ld_a_c,     ld_a_d,     ld_a_e,     ld_a_h,     ld_a_l,     ld_a_hl,    ld_a_a,
/*0x8-*/    add_a_b,    add_a_c,    add_a_d,    add_a_e,    add_a_h,    add_a_l,    add_a_hl,   add_a_a,    adc_a_b,    adc_a_c,    adc_a_d,    adc_a_e,    adc_a_h,    adc_a_l,    adc_a_hl,   adc_a_a,
/*0x9-*/    sub_b,      sub_c,      sub_d,      sub_e,      sub_h,      sub_l,      sub_hl,     sub_a,      sbc_b,      sbc_c,      sbc_d,      sbc_e,      sbc_h,      sbc_l,      sbc_hl,     sbc_a,
/*0xA-*/    and_b,      and_c,      and_d,      and_e,      and_h,      and_l,      and_hl,     and_a,      xor_b,      xor_c,      xor_d,      xor_e,      xor_h,      xor_l,      xor_hl,     xor_a,
/*0xB-*/    or_b,       or_c,       or_d,       or_e,       or_h,       or_l,       or_hl,      or_a,       cp_b,       cp_c,       cp_d,       cp_e,       cp_h,       cp_l,       cp_hl,      cp_a,
/*0xC-*/    ret_nz,     pop_bc,     jp_nz,      jp,         call_nz,    push_bc,    add_a_d8,   rst_00h,    ret_z,      ret,        jp_z,       prefix_cb,  call_z_a16, call_a16,   adc_a_d8,   rst_08h,
/*0xD-*/    ret_nc,     pop_de,     jp_nc,      INVALID,    call_nc,    push_de,    sub_d8,     rst_10h,    ret_c,      reti,       jp_c,       INVALID,    call_c_a16, INVALID,    sbc_d8,     rst_18h,
/*0xE-*/    ldh_0a_a,   pop_hl,     ld_0c_a,    INVALID,    INVALID,    push_hl,    and_d8,     rst_20h,    add_sp_r8,  jp_0hl,     ld_0a16_a,  INVALID,    INVALID,    INVALID,    xor_d8,     rst_28h,
/*0xF-*/    ldh_a_0a,   pop_af,     ld_a_0c,    di,         INVALID,    push_af,    or_d8,      rst_30h,    ldhl_sp_r8, ld_sp_hl,   ld_a_0a16,  ei,         INVALID,    INVALID,    cp_d8,      rst_38h,
};

LR35902_OP_FN opCB[256] = {
/*          0x-0        0x-1        0x-2        0x-3        0x-4        0x-5        0x-6        0x-7        0x-8        0x-9        0x-A        0x-B        0x-C        0x-D        0x-E        0x-F */
/*0x0-*/    rlc_b,      rlc_c,      rlc_d,      rlc_e,      rlc_h,      rlc_l,      rlc_hl,     rlc_a,      rrc_b,      rrc_c,      rrc_d,      rrc_e,      rrc_h,      rrc_l,      rrc_hl,     rrc_a,
/*0x1-*/    rl_b,       rl_c,       rl_d,       rl_e,       rl_h,       rl_l,       rl_hl,      rl_a,       rr_b,       rr_c,       rr_d,       rr_e,       rr_l,       rr_l,       rr_hl,      rr_a,
/*0x2-*/    sla_b,      sla_c,      sla_d,      sla_e,      sla_h,      sla_l,      sla_hl,     sla_a,      sra_b,      sra_c,      sra_d,      sra_e,      sra_h,      sra_l,      sra_hl,     sra_a,
/*0x3-*/    swap_b,     swap_c,     swap_d,     swap_e,     swap_h,     swap_l,     swap_hl,    swap_a,     srl_b,      srl_c,      srl_d,      srl_e,      srl_h,      srl_l,      srl_hl,     srl_c,
/*0x4-*/    bit_0_b,    bit_0_c,    bit_0_d,    bit_0_e,    bit_0_h,    bit_0_l,    bit_0_hl,   bit_0_a,    bit_1_b,    bit_1_c,    bit_1_d,    bit_1_e,    bit_1_h,    bit_1_l,    bit_1_hl,   bit_1_a,
/*0x5-*/    bit_2_b,    bit_2_c,    bit_2_d,    bit_2_e,    bit_2_h,    bit_2_l,    bit_2_hl,   bit_2_a,    bit_3_b,    bit_3_c,    bit_3_d,    bit_3_e,    bit_3_h,    bit_3_l,    bit_3_hl,   bit_3_a,
/*0x6-*/    bit_4_b,    bit_4_c,    bit_4_d,    bit_4_e,    bit_4_h,    bit_4_l,    bit_4_hl,   bit_4_a,    bit_5_b,    bit_5_c,    bit_5_d,    bit_5_e,    bit_5_h,    bit_5_l,    bit_5_hl,   bit_5_a,
/*0x7-*/    bit_6_b,    bit_6_c,    bit_6_d,    bit_6_e,    bit_6_h,    bit_6_l,    bit_6_hl,   bit_6_a,    bit_7_b,    bit_7_c,    bit_7_d,    bit_7_e,    bit_7_h,    bit_7_l,    bit_7_hl,   bit_7_a,
/*0x8-*/    res_0_b,    res_0_c,    res_0_d,    res_0_e,    res_0_h,    res_0_l,    res_0_hl,   res_0_a,    res_1_b,    res_1_c,    res_1_d,    res_1_e,    res_1_h,    res_1_l,    res_1_hl,   res_1_a,
/*0x9-*/    res_2_b,    res_2_c,    res_2_d,    res_2_e,    res_2_h,    res_2_l,    res_2_hl,   res_2_a,    res_3_b,    res_3_c,    res_3_d,    res_3_e,    res_3_h,    res_3_l,    res_3_hl,   res_3_a,
/*0xA-*/    res_4_b,    res_4_c,    res_4_d,    res_4_e,    res_4_h,    res_4_l,    res_4_hl,   res_4_a,    res_5_b,    res_5_c,    res_5_d,    res_5_e,    res_5_h,    res_5_l,    res_5_hl,   res_5_a,
/*0xB-*/    res_6_b,    res_6_c,    res_6_d,    res_6_e,    res_6_h,    res_6_l,    res_6_hl,   res_6_a,    res_7_b,    res_7_c,    res_7_d,    res_7_e,    res_7_h,    res_7_l,    res_7_hl,   res_7_a,
/*0xC-*/    set_0_b,    set_0_c,    set_0_d,    set_0_e,    set_0_h,    set_0_l,    set_0_hl,   set_0_a,    set_1_b,    set_1_c,    set_1_d,    set_1_e,    set_1_h,    set_1_l,    set_1_hl,   set_1_a,
/*0xD-*/    set_2_b,    set_2_c,    set_2_d,    set_2_e,    set_2_h,    set_2_l,    set_2_hl,   set_2_a,    set_3_b,    set_3_c,    set_3_d,    set_3_e,    set_3_h,    set_3_l,    set_3_hl,   set_3_a,
/*0xE-*/    set_4_b,    set_4_c,    set_4_d,    set_4_e,    set_4_h,    set_4_l,    set_4_hl,   set_4_a,    set_5_b,    set_5_c,    set_5_d,    set_5_e,    set_5_h,    set_5_l,    set_5_hl,   set_5_a,
/*0xF-*/    set_6_b,    set_6_c,    set_6_d,    set_6_e,    set_6_h,    set_6_l,    set_6_hl,   set_6_a,    set_7_b,    set_7_c,    set_7_d,    set_7_e,    set_7_h,    set_7_l,    set_7_hl,   set_7_a,
};

/**
 * Execute an operation.
 */
void exec_op(void)
{
    uint8 opcode = 0x00;//mem_read(c->r.pc++);
    (op[opcode])();
}

