/*
 * Copyright 2013 Jason M. Baker
 */

#include "xplat/types.hpp"
#include "Processors/Nintendo/LR35902/LR35902.hpp"

/*
FORMAT for processor operation functions.
<mnemonic> [#1 |     #2] [Z H N C]
Where #1 is the length in bytes read from the stack.
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

/* Calculate flags */
//#define CALC_Z_N_H(Z, N, H)         (((Z ? 0x04 : 0x00) | (N ? 0x02 : 0x00) | (H ? 0x01 : 0x00)) << (7-3+1))
#define CALC_Z_N_H_C(Z, N, H, C)    ((Z ? LR35902_FLAG_ZERO : 0x00) | (N ? LR35902_FLAG_SUBTRACT : 0x00) | (H ? LR35902_FLAG_HALF_CARRY : 0x00) | (C ? LR35902_FLAG_CARRY : 0x00))

/* Optimizations for rotations. */
#define ROTATE_LEFT(VALUE) (((VALUE) << 1) | (VALUE) >> (sizeof(VALUE) - 1))
#define ROTATE_RIGHT(VALUE) ((((VALUE) >> 1) | (VALUE) << (sizeof(VALUE) - 1)))

#define PRE_OP_FUNC static void

/**
 * Convert 2 8 bit registers into a 16 bit register.
 */
#define GET_REG16(REG1, REG2) (((REG1) << 8) | (REG2))

/*********************************************************************************************************************\
| Misceleanous Commands                                                                                               |
\*********************************************************************************************************************/

/* nop          [1  |     4] [- - - -] */
void LR35902::nop()
{
    /* @TODO Affect clock cycle. */
}

/* stop         [2  |     4] [- - - -] */
void LR35902::stop()
{
    /* @TODO Affect clock cycle. */
}

/* halt         [1  |     4] [- - - -] */
void LR35902::halt()
{
    /* @TODO */
}

/* di           [1  |     4] [- - - -] */
void LR35902::di()
{
    /* @TODO */
}

/* ei           [1  |     4] [- - - -] */
void LR35902::ei()
{
    /* @TODO */
}

/*********************************************************************************************************************\
| Jump, Return, Call, Reset Commands                                                                                  |
\*********************************************************************************************************************/

/* jr_n         [1  |     4] [- - - -] */
void LR35902::jr_n()
{
    /* @TODO Affect clock cycle. */
    /* @TODO Read from memory */
    /* @TODO Update PC */
}

/* jr_cc_n      [1  |  12/8] [- - - -] */
void LR35902::jr_cc_n(bool negate, uint8 flags)
{
    /* @TODO Affect clock cycle. */
    /* @TODO Read from memory */
    /* @TODO Update stack/PC */
}

/* jp_nn        [1  |    16] [- - - -] */
void LR35902::jp_nn()
{
    /* @TODO Affect clock cycle. */
    /* @TODO Read from memory */
    /* @TODO Perform Jump */
}

/* jp_hl        [1  |    16] [- - - -] */
void LR35902::jp_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO Read from memory */
    /* @TODO Perform Jump */
}

/* jp_cc_nn     [1  | 16/12] [- - - -] */
void LR35902::jp_cc_nn(bool set, uint8 flags)
{
    /* @TODO Affect clock cycle. */
    /* @TODO Check condition. */
    /* @TODO Read from memory */
    /* @TODO Perform Jump */
}

/* call_cc_nn   [1  |    24] [- - - -] */
void LR35902::call_nn()
{
    /* @TODO Affect clock cycle. */
    /* @TODO push address of next instruction onto stack */
    /* @TODO Read from memory */
    /* @TODO Perform Jump */
}

/* call_cc_nn   [1  | 16/12] [- - - -] */
void LR35902::call_cc_nn(bool set, uint8 flags)
{
    /* @TODO Affect clock cycle. */
    /* @TODO Check condition */
    /* @TODO push address of next instruction onto stack */
    /* @TODO Read from memory */
    /* @TODO Perform Jump */
}

/* ret          [1  |    16] [- - - -] */
void LR35902::ret()
{
    /* @TODO Affect clock cycle. */
    /* @TODO Read from memory */
    /* @TODO Perform Jump */
}

/* reti         [1  |    16] [- - - -] */
void LR35902::reti()
{
    /* @TODO Affect clock cycle. */
    /* @TODO Read from memory */
    /* @TODO Perform Jump */
    /* @TODO enable interupts */
}

/* ret_cc       [1  |  20/8] [- - - -] */
void LR35902::ret_cc(bool set, uint8 flags)
{
    /* @TODO Affect clock cycle. */
    /* @TODO Check condition */
    /* @TODO Read from memory */
    /* @TODO Perform Jump */
}

/* rst_n        [1  |    16] [- - - -] */
void LR35902::rst_n(uint8 offset)
{
    /* @TODO Affect clock cycle. */
    /* @TODO push current address onto the stack. */
    /* @TODO Perform Jump. */
}

/*********************************************************************************************************************\
| 8 Bit Load Commands                                                                                                 |
\*********************************************************************************************************************/

/* ld_rr_a      [1  |     8] [- - - -] */
void LR35902::ld_rr_a(uint8 &hReg, uint8 &lReg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO Read from memory */
}

/* ld_a_rr      [1  |     8] [- - - -] */
void LR35902::ld_a_rr(uint8 &hReg, uint8 &lReg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO Store to memory */
}

/* ld_rr_n      [2  |     8] [- - - -] */
void LR35902::ld_r_n(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    reg = 0x00;/* @TODO read from memory */
}

/* ld_hl_n      [2  |    12] [- - - -] */
void LR35902::ld_hl_n()
{
    /* @TODO Affect clock cycle. */
    /* @TODO read n from stack */
    /* @TODO Write Memory n @ (HL) */
}

/* ld_r_r       [1  |     4] [- - - -] */
void LR35902::ld_r_r(uint8 &reg1, uint8 &reg2)
{
    /* @TODO Affect clock cycle. */
    reg1 = reg2;
}

/* ld_r_hl      [1  |     8] [- - - -] */
void LR35902::ld_r_hl(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    reg = 0x00;/* @TODO read memory from hl*/
}

/* ld_hl_r      [1  |     8] [- - - -] */
void LR35902::ld_hl_r(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    reg = 0x00;/* @TODO write memory to hl*/
}

/* ldh_n_a      [2  |    12] [- - - -] */
void LR35902::ldh_n_a()
{
    /* @TODO Affect clock cycle. */
    /* @TODO write a to memory. */
}

/* ldh_a_n      [2  |    12] [- - - -] */
void LR35902::ldh_a_n()
{
    /* @TODO Affect clock cycle. */
    /* @TODO Read from memory. */
}

/* ld_c_a       [2  |    12] [- - - -] */
void LR35902::ld_c_a()
{
    /* @TODO Affect clock cycle. */
    /* @TODO write a to memory. */
}

/* ld_a_c       [2  |    12] [- - - -] */
void LR35902::ld_a_c()
{
    /* @TODO Affect clock cycle. */
    /* @TODO Read from memory. */
}

/* ld_nn_a      [3  |    16] [- - - -] */
void LR35902::ld_nn_a()
{
    /* @TODO Affect clock cycle. */
    /* @TODO write a to memory. */
}

/* ld_a_nn      [3  |    16] [- - - -] */
void LR35902::ld_a_nn()
{
    /* @TODO Affect clock cycle. */
    /* @TODO Read from memory. */
}

/*********************************************************************************************************************\
| 8 Bit Arithmetic Commands                                                                                           |
\*********************************************************************************************************************/

/* add_a_r      [1  |     4] [Z 0 H C] */
void LR35902::add_a_r(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* add_a_hl     [1  |     8] [Z 0 H C] */
void LR35902::add_a_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* add_a_n      [1  |     8] [Z 0 H C] */
void LR35902::add_a_n()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* adc_a_r      [1  |     4] [Z 0 H C] */
void LR35902::adc_a_r(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* adc_a_hl     [1  |     8] [Z 0 H C] */
void LR35902::adc_a_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* adc_a_n      [1  |     8] [Z 0 H C] */
void LR35902::adc_a_n()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* sub_a_r      [1  |     4] [Z 1 H C] */
void LR35902::sub_a_r(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* sub_a_hl     [1  |     8] [Z 1 H C] */
void LR35902::sub_a_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* add_a_n      [1  |     8] [Z 1 H C] */
void LR35902::sub_a_n()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* sbc_a_r      [1  |     4] [Z 1 H C] */
void LR35902::sbc_a_r(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* sbc_a_hl     [1  |     8] [Z 1 H C] */
void LR35902::sbc_a_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* sbc_a_hl     [1  |     8] [Z 1 H C] */
void LR35902::sbc_a_n()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* and_a_r      [1  |     4] [Z 0 1 0] */
void LR35902::and_a_r(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* and_a_hl     [1  |     8] [Z 0 1 0] */
void LR35902::and_a_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* and_a_n      [1  |     8] [Z 0 1 0] */
void LR35902::and_a_n()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* xor_a_r      [1  |     4] [Z 0 0 0] */
void LR35902::xor_a_r(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* xor_a_hl     [1  |     8] [Z 0 0 0] */
void LR35902::xor_a_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* xor_a_n      [1  |     8] [Z 0 0 0] */
void LR35902::xor_a_n()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* or_a_r       [1  |     4] [Z 0 0 0] */
void LR35902::or_a_r(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* or_a_hl      [1  |     8] [Z 0 0 0] */
void LR35902::or_a_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* or_a_n       [1  |     8] [Z 0 0 0] */
void LR35902::or_a_n()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* cp_a_r       [1  |     4] [Z 1 H C] */
void LR35902::cp_a_r(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* cp_a_hl      [1  |     8] [Z 1 H C] */
void LR35902::cp_a_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* cp_a_n       [1  |     8] [Z 1 H C] */
void LR35902::cp_a_n()
{
    /* @TODO Affect clock cycle. */
    /* @TODO implement */
}

/* inc_r        [1  |     4] [Z 0 H -] */
void LR35902::inc_r(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    ++reg;
    //r.f = CALC_Z_N_H_C(0 == reg, 0, reg & 0x0F);
}

/* inc_hl       [1  |    12] [Z 0 H -] */
void LR35902::inc_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO Read the memory value (HL) */
    /* @TODO Increment the value */
    /* @TODO Store the value back into memory (HL) */
    /* @TODO Set registers */
}

/* dec_r        [1  |     4] [Z 1 H -] */
void LR35902::dec_r(uint8 &reg)
{
    /* @TODO Affect clock cycle. */
    --reg;
    //this->r.f = CALC_Z_N_H_C(0 == reg, 1, reg & 0x0F);
}

/* decc_hl      [1  |    12] [Z 1 H -] */
void LR35902::dec_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO Read the memory value (HL) */
    /* @TODO Increment the value */
    /* @TODO Store the value back into memory (HL) */
    /* @TODO Set registers */
}

/* rlca         [1  |     4] [0 0 0 C] */
void LR35902::rlca()
{
    /* @TODO Affect clock cycle. */
    this->r.a = ROTATE_LEFT(this->r.a);
    //this->r.f = CALC_Z_N_H_C(0, 0, 0, this->r.a & 0x01);
}

/* rlca         [1  |     4] [0 0 0 C] */
void LR35902::rla()
{
    /* @TODO Affect clock cycle. */
    /* @TODO */
}

/* rrca         [1  |     4] [0 0 0 C] */
void LR35902::rrca()
{
    /* @TODO Affect clock cycle. */
    /* @TODO */
}

/* rra          [1  |     4] [0 0 0 C] */
void LR35902::rra()
{
    /* @TODO Affect clock cycle. */
    //this->r.f = CALC_Z_N_H_C(0, 0, 0, this->r.a & 0x01);
    this->r.a = ROTATE_RIGHT(this->r.a);
}

/* daa          [1  |     4] [Z - 0 C] */
void LR35902::daa()
{
    /* @TODO Affect clock cycle. */
    /* @TODO BCD Encode A. */
}

/* cpl          [1  |     4] [- 1 1 -] */
void LR35902::cpl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO BCD Encode A. */
}

/* scf          [1  |     4] [- 0 0 1] */
void LR35902::scf()
{
    /* @TODO Affect clock cycle. */
    //this->r.f = CALC_Z_N_H_C((), 0, 0, true);
}

/* ccf          [1  |     4] [- 0 0 C] */
void LR35902::ccf()
{
    /* @TODO Affect clock cycle. */
    //this->r.f = CALC_N_H_C(0, 0, !(this.r.f & LR35902_CARRY_FLAG));
}

/*********************************************************************************************************************\
| 16 Bit Load Commands                                                                                                |
\*********************************************************************************************************************/

/* ld_rr_nn     [3  |    12] [- - - -] */
void LR35902::ld_rr_nn(uint8 &hReg, uint8 &lReg)
{
    /* @TODO Affect clock cycle. */
    hReg = 0x00;/* @TODO read from memory */
    lReg = 0x00;/* @TODO read from memory */
}
void LR35902::ld_rr_nn(uint16 &reg)
{
    /* @TODO Affect clock cycle. */
    reg  = 0x00 << 0;/* @TODO read from memory */
    reg |= 0x00 << 8;/* @TODO read from memory */
}

/* ld_nn_sp     [3  |    20] [- - - -] */
void LR35902::ld_nn_sp()
{
    /* @TODO Affect clock cycle. */
    uint16 addr = 0x00; /* @TODO read from memory */
    addr |= 0x00;       /* @TODO read from memory */
    /* @TODO write to memory sp */
}

/* ldi_hl_a     [1  |     8] [- - - -] */
void LR35902::ldi_hl_a()
{
    /* @TODO Affect clock cycle. */
    /* @TODO write to memory hl */
    /* @TODO increment hl */
}

/* ldi_a_hl     [1  |     8] [- - - -] */
void LR35902::ldi_a_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO read from memory hl */
    /* @TODO increment hl */
}

/* ldd_hl_a     [1  |     8] [- - - -] */
void LR35902::ldd_hl_a()
{
    /* @TODO Affect clock cycle. */
    /* @TODO write to memory hl */
    /* @TODO deccrement hl */
}

/* ldd_a_hl     [1  |     8] [- - - -] */
void LR35902::ldd_a_hl()
{
    /* @TODO Affect clock cycle. */
    /* @TODO read from memory hl */
    /* @TODO deccrement hl */
}

/* ldhl_sp_n    [2  |    12] [- - - -] */
void LR35902::ldhl_sp_n()
{
    /* @TODO store SP+N into hl. */
}

/* ld_sp_hl     [1  |     8] [- - - -] */
void LR35902::ld_sp_hl()
{
    /* @TODO store HL into SP. */
}

/* pop_rr       [1  |    12] [- - - -] */
void LR35902::pop_rr(uint8 &hReg, uint8 &lReg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO write to memory from rr */
}

/* push_rr      [1  |    12] [- - - -] */
void LR35902::push_rr(uint8 &hReg, uint8 &lReg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO read from memory into rr */
}

/*********************************************************************************************************************\
| 16 Bit Arithmetic Commands                                                                                          |
\*********************************************************************************************************************/

/* add_hl_rr    [1  |     8] [- 0 H C] */
void LR35902::add_hl_rr(uint8 &hReg, uint8 &lReg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO Figure out how to calculate this in general*/
}
void LR35902::add_hl_rr(uint16 &reg)
{
    /* @TODO Affect clock cycle. */
    /* @TODO Figure out how to calculate this in general*/
}

/* add_sp_n     [2  |    16] [0 0 H C] */
void LR35902::add_sp_n()
{
    /* @TODO Affect clock cycle. */
    /* @TODO Figure out how to calculate this in general */
}

/* inc_rr       [1  |     8] [- - - -] */
void LR35902::inc_rr(uint8 &hReg, uint8 &lReg)
{
    /* @TODO Affect clock cycle. */
    ++lReg;
    if (lReg == 0) {
        ++hReg;
    }
}
void LR35902::inc_rr(uint16 &reg)
{
    /* @TODO Affect clock cycles */
    ++reg;
}

/* dec_rr       [1  |     8] [Z 0 H -] */
void LR35902::dec_rr(uint8 &hReg, uint8 &lReg)
{
    /* @TODO Affect clock cycle. */
    --lReg;
    if (0xFF == lReg) {
        --hReg;
    }
}
void LR35902::dec_rr(uint16 &reg)
{
    /* @TODO Affect clock cycle. */
    --reg;
}

/*********************************************************************************************************************\
| CBX Commands                                                                                                        |
\*********************************************************************************************************************/

/* rlc_r        [2  |     8] [Z 0 0 C] */
void LR35902::rlc_r(uint8 &reg)
{
    /* @TODO */
}

/* rlc_hl       [2  |    16] [Z 0 0 C] */
void LR35902::rlc_hl()
{
    /* @TODO */
}

/* rl_r         [2  |     8] [Z 0 0 C] */
void LR35902::rl_r(uint8 &reg)
{
    /* @TODO */
}

/* rl_hl        [2  |    16] [Z 0 0 C] */
void LR35902::rl_hl()
{
    /* @TODO */
}

/* rrc_r        [2  |     8] [Z 0 0 C] */
void LR35902::rrc_r(uint8 &reg)
{
    /* @TODO */
}

/* rrc_hl       [2  |    16] [Z 0 0 C] */
void LR35902::rrc_hl()
{
    /* @TODO */
}

/* rr_r         [2  |     8] [Z 0 0 C] */
void LR35902::rr_r(uint8 &reg)
{
    /* @TODO */
}

/* rr_hl        [2  |    16] [Z 0 0 C] */
void LR35902::rr_hl()
{
    /* @TODO */
}

/* sla_r        [2  |     8] [Z 0 0 C] */
void LR35902::sla_r(uint8 &reg)
{
    /* @TODO */
}

/* sla_hl       [2  |    16] [Z 0 0 C] */
void LR35902::sla_hl()
{
    /* @TODO */
}

/* sra_r        [2  |     8] [Z 0 0 0] */
void LR35902::sra_r(uint8 &reg)
{
    /* @TODO */
}

/* sra_hl       [2  |    16] [Z 0 0 0] */
void LR35902::sra_hl()
{
    /* @TODO */
}

/* srl_r        [2  |     8] [Z 0 0 C] */
void LR35902::srl_r(uint8 &reg)
{
    /* @TODO */
}

/* srl_hl       [2  |    16] [Z 0 0 C] */
void LR35902::srl_hl()
{
    /* @TODO */
}

/* swap_r       [2  |     8] [Z 0 0 0] */
void LR35902::swap_r(uint8 &reg)
{
    /* @TODO */
}

/* swap_hl      [2  |    16] [Z 0 0 0] */
void LR35902::swap_hl()
{
    /* @TODO */
}

/* bit          [2  |     8] [Z 0 1 -] */
void LR35902::bit_b_r(uint8 bit, const uint8 &reg)
{
    this->r.f = CALC_Z_N_H_C(reg & (1 << bit), 0, 1, this->r.f & LR35902_FLAG_CARRY);
}

/* bit_hl       [2  |    16] [Z 0 1 -] */
void LR35902::bit_b_hl(const uint8 bit)
{
    uint8 value = 0x00; /* @TODO read hl from memory. */
    this->bit_b_r(bit, value);
    /* @TODO Write value back to memory. */
}

/* res          [2  |     8] [- - - -] */
void LR35902::res_b_r(const uint8 bit, uint8 &reg)
{
    reg &= 0xFFFF ^ (1 << bit);
}

/* res_hl       [2  |    16] [- - - -] */
void LR35902::res_b_hl(const uint8 bit)
{
    uint8 value = 0x00; /* @TODO read hl from memory. */
    this->res_b_r(bit, value);
    /* @TODO Write value back to memory. */
}

/* set          [2  |     8] [- - - -] */
void LR35902::set_b_r(const uint8 bit, uint8 &reg)
{
    reg |= (1 << bit);
}

/* set_hl       [2  |    16] [Z 0 1 -] */
void LR35902::set_b_hl(const uint8 bit)
{
    uint8 value = 0x00; /* @TODO read hl from memory. */
    this->set_b_r(bit, value);
    /* @TODO Write value back to memory. */
}

#undef PRE_OP_FUNC

