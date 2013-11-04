#include "Processors/Processor.hpp"

namespace SiNES { namespace Processors { namespace Nintendo {
    /**
     * The LR35902 Processor class.
     */
    class LR35902 : public SiNES::Processors::Processor {
    public:
        /**
         * Constructor for an LR35902 processor.
         */
        LR35902();

        /**
         * Destructor for an LR35902 processor.
         */
        virtual ~LR35902();

        /**
         * Execute the next processor level operation.
         */
        virtual void execOp();

    protected:
        /************************************************\
        |* Op Code Functions                            *|
        \************************************************/
        /*
        FORMAT for processor operation functions: <mnemonic> [#1 |    #2] [Z H N C]
        Where:
            mnemonic            : Is the processor operation mnemonic associated with the instruction
            #1                  : The length in bytes read from the stack.
            #2                  : The duration in clock cycles.
            Z - Zero Flag       : Set when a math operation is zero or two values match with CP.
            H - Subtract Flag   : Set if the last operation used subtraction.
            N - Half Carry Flag : If the lower nibble carried in the math operation.
            C - Carry Flag      : Set if a carry occurred from the last math operation or register A is smaller in with CP.
        Z,H,N,C are flags that were affected by the operation.
            * If the flag is marked by a "0" it is reset after instruction run.
            * If the flag is marked by a "1" it is set after instruction run.
            * If the flag is marked by a "-" it is unchanged.
            * If the flag is marked by the corresponding symbol it is affected by the function as normal.
        */

        /************************\
        |* Misc. Operations     *|
        \************************/

        /**
         * The no operation op.
         * nop          [1  |     4] [- - - -]
         */
        void nop();

        /**
         * The stop operation.
         * stop         [2  |     4] [- - - -]
         */
        void stop();

        /**
         * The halt operation.
         * halt         [1  |     4] [- - - -]
         */
        void halt();

        /**
         * Disable interrupts.
         * di           [1  |     4] [- - - -]
         */
        void di();

        /**
         * Enable interrupts.
         * ei           [1  |     4] [- - - -]
         */
        void ei();

        /************************\
        |* Jump/Call Operations *|
        \************************/

        /**
         * Jump return operation.
         * jr_n         [1  |    12] [- - - -]
         */
        void jr_n();

        /**
         * Jump return operation on condition.
         * jr_cc_n      [1  |  12/8] [- - - -]
         *
         * @param set       [IN]        True if the flag should be checked for set.
         * @param flags     [IN]        The flags to check for being set.
         */
        void jr_cc_n(bool set, uint8 flags);

        /**
         * Jump operation.
         * jp_nn        [1  |    16] [- - - -]
         */
        void jp_nn();

        /**
         * Jump operation based on value (HL).
         * jp_hl        [1  |    16] [- - - -]
         */
        void jp_hl();

        /**
         * Jump operation on condition.
         * jp_cc_nn     [1  | 16/12] [- - - -]
         *
         * @param set       [IN]        True if the flag should be checked for set.
         * @param flags     [IN]        The flags to check for being set.
         */
        void jp_cc_nn(bool set, uint8 flags);

        /**
         * The call operation.
         * call_cc_nn   [1  |    24] [- - - -]
         */
        void call_nn();

        /**
         * Call operation on condition.
         * call_cc_nn   [1  | 16/12] [- - - -]
         *
         * @param set       [IN]        True if the flag should be checked for set.
         * @param flags     [IN]        The flags to check for being set.
         */
        void call_cc_nn(bool set, uint8 flags);

        /**
         * return operation on condition.
         * ret          [1  |    16] [- - - -]
         */
        void ret();

        /**
         * Return operation and enable interupt.
         * reti         [1  |    16] [- - - -]
         */
        void reti();

        /**
         * return operation on condition.
         * ret_cc       [1  |  20/8] [- - - -]
         *
         * @param set       [IN]        True if the flag should be checked for set.
         * @param flags     [IN]        The flags to check for being set.
         */
        void ret_cc(bool set, uint8 flags);

        /**
         * Push present address onto the stack and jump to address 0x0000 + n.
         * rst_n        [1  |    16] [- - - -]
         *
         * @param address   [IN]        The offset to jump to.
         */
        void rst_n(uint8 offset);

        /************************\
        |* 8 Bit Load Ops       *|
        \************************/

        /**
         * Store the accumulator register into the address in the provided register.
         * ld_rr_a      [1  |     8] [- - - -]
         *
         * @param hReg      [IN]        High byte of the register.
         * @param lReg      [IN]        Low byte of the register.
         */
        void ld_rr_a(uint8 &hReg, uint8 &lReg);

        /**
         * Store the value at the address in the provided register into the accumulator.
         * ld_a_rr      [1  |     8] [- - - -]
         *
         * @param hReg      [IN]        High byte of the register.
         * @param lReg      [IN]        Low byte of the register.
         */
        void ld_a_rr(uint8 &hReg, uint8 &lReg);

        /**
         * Store the 8 bit value into the provided 8 bit register.
         * ld_rr_n      [2  |     8] [- - - -]
         *
         * @param reg       [IN]        Register to act on.
         */
        void ld_r_n(uint8 &reg);

        /**
         * Load register 1 into register 2.
         * ld_r_r       [1  |     4] [- - - -]
         *
         * @param reg1      [IN]        The register to store to.
         * @param reg2      [IN]        The register to store from.
         */
        void ld_r_r(uint8 &reg1, uint8 &reg2);

        /**
         * Load (HL) into register 2.
         * ld_r_hl      [1  |     8] [- - - -]
         *
         * @param reg       [IN]        The register to store to.
         */
        void ld_r_hl(uint8 &reg);

        /**
         * Load register 2 into (HL).
         * ld_hl_r      [1  |     8] [- - - -]
         *
         * @param reg       [IN]        The register to store to.
         */
        void ld_hl_r(uint8 &reg);

        /**
         * Store the contents of the top stack item into (HL).
         * ld_hl_n      [2  |    12] [- - - -]
         */
        void ld_hl_n();

        /**
         * Store register A into memory address $FF00 + n.
         * ldh_n_a      [2  |    12] [- - - -]
         */
        void ldh_n_a();

        /**
         * Store memory address $FF00 + n's value into register A.
         * ldh_a_n      [2  |    12] [- - - -]
         */
        void ldh_a_n();

        /**
         * Store register A into memory address $FF00 + register c.
         * ld_c_a       [2  |    12] [- - - -]
         */
        void ld_c_a();

        /**
         * Store memory address $FF00 + register C's value into register A.
         * ld_a_c       [2  |    12] [- - - -]
         */
        void ld_a_c();

        /**
         * Store register A into memory address nn.
         * ld_nn_a      [3  |    16] [- - - -]
         */
        void ld_nn_a();

        /**
         * Store memory address nn's valu  into register A.
         * ld_a_nn      [3  |    16] [- - - -]
         */
        void ld_a_nn();

        /************************\
        |* 8 Bit Arithmetic Ops *|
        \************************/

        /**
         * Add register to register A.
         * add_a_r      [1  |     4] [Z 0 H C]
         *
         * @param reg       [IN]        Register to add to A.
         */
        void add_a_r(uint8 &reg);

        /**
         * Add (HL) to register A.
         * add_a_hl     [1  |     8] [Z 0 H C]
         */
        void add_a_hl();

        /**
         * Add value on stack to register A.
         * add_a_n      [1  |     8] [Z 0 H C]
         */
        void add_a_n();

        /**
         * Add register + carry bit to register A.
         * adc_a_r      [1  |     4] [Z 0 H C]
         *
         * @param reg       [IN]        Register to add to A.
         */
        void adc_a_r(uint8 &reg);

        /**
         * Add (HL) + carry bit to register A.
         * adc_a_hl     [1  |     8] [Z 0 H C]
         */
        void adc_a_hl();

        /**
         * Add value on stack + carry bit to register A.
         * adc_a_n      [1  |     8] [Z 0 H C]
         */
        void adc_a_n();

        /**
         * Subtract value in register from register A.
         * sub_a_r      [1  |     4] [Z 1 H C]
         *
         * @param reg       [IN]        Register to subtract A.
         */
        void sub_a_r(uint8 &reg);

        /**
         * Subtract (HL) from register A.
         * sub_a_hl     [1  |     8] [Z 1 H C]
         */
        void sub_a_hl();

        /**
         * subtract value on stack from register A.
         * add_a_n      [1  |     8] [Z 1 H C]
         */
        void sub_a_n();

        /**
         * Subtract register + carry bit from register A.
         * sbc_a_r      [1  |     4] [Z 1 H C]
         *
         * @param reg       [IN]        Register to add to A.
         */
        void sbc_a_r(uint8 &reg);

        /**
         * Subtract + carry bit from register A.
         * sbc_a_hl     [1  |     8] [Z 1 H C]
         */
        void sbc_a_hl();

        /**
         * Subtract value on stack + carry bit from register A.
         * sbc_a_n      [1  |     8] [Z 1 H C]
         */
        void sbc_a_n();

        /**
         * Perform A = A & R.
         * and_a_r      [1  |     4] [Z 0 1 0]
         *
         * @param reg       [IN]        Register to and with A.
         */
        void and_a_r(uint8 &reg);

        /**
         * Perform A = A | (HL).
         * and_a_hl     [1  |     8] [Z 0 1 0]
         */
        void and_a_hl();

        /**
         * Perform A = A | n.
         * and_a_n      [1  |     8] [Z 0 1 0]
         */
        void and_a_n();

        /**
         * Perform A = A ^ R.
         * xor_a_r      [1  |     4] [Z 0 0 0]
         *
         * @param reg       [IN]        Register to xor with A.
         */
        void xor_a_r(uint8 &reg);

        /**
         * Perform A = A ^ (HL).
         * xor_a_hl     [1  |     8] [Z 0 0 0]
         */
        void xor_a_hl();

        /**
         * Perform A = A ^ n.
         * xor_a_n      [1  |     8] [Z 0 0 0]
         */
        void xor_a_n();

        /**
         * Perform A = A | R.
         * or_a_r       [1  |     4] [Z 0 0 0]
         *
         * @param reg       [IN]        Register to or with A.
         */
        void or_a_r(uint8 &reg);

        /**
         * Perform A = A | (HL).
         * or_a_hl      [1  |     8] [Z 0 0 0]
         */
        void or_a_hl();

        /**
         * Perform A = A | n.
         * or_a_n       [1  |     8] [Z 0 0 0]
         */
        void or_a_n();

        /**
         * Compare register with register A.
         * cp_a_r       [1  |     4] [Z 1 H C]
         *
         * @param reg       [IN]        Register to subtract A.
         */
        void cp_a_r(uint8 &reg);

        /**
         * Compare (HL) with register A.
         * cp_a_hl      [1  |     8] [Z 1 H C]
         */
        void cp_a_hl();

        /**
         * Compare value on stack with register A.
         * cp_a_n       [1  |     8] [Z 1 H C]
         */
        void cp_a_n();

        /**
         * Increment the 8 bit register.
         * inc_r        [1  |     4] [Z 0 H -]
         *
         * @param reg       [IN]        Register to act on.
         */
        void inc_r(uint8 &reg);

        /**
         * Increment (hl).
         * inc_hl       [1  |    12] [Z 0 H -]
         */
        void inc_hl();

        /**
         * Decrement the 8 bit register.
         * dec_r        [1  |     4] [Z 1 H -]
         *
         * @param reg       [IN]        Register to act on.
         */
        void dec_r(uint8 &reg);

        /**
         * Decrement (hl).
         * decc_hl      [1  |    12] [Z 1 H -]
         */
        void dec_hl();

        /**
         * Rotate A left.  Old bit 7 to carry flag register.
         * rrca         [1  |     4] [0 0 0 C]
         */
        void rlca();

        /**
         * Rotate A left through carry flag.
         * rlca         [1  |     4] [0 0 0 C]
         */
        void rla();

        /**
         * Rotate A right.  Old bit 0 to carry flag register.
         * rrca         [1  |     4] [0 0 0 C]
         */
        void rrca();

        /**
         * Rotate A right through carry flag.
         * rrca         [1  |     4] [0 0 0 C]
         */
        void rra();

        /**
         * Decimal adjust register A into BCD format.
         * daa          [1  |     4] [Z - 0 C]
         */
        void daa();

        /**
         * Take the complement of register A.
         * cpl          [1  |     4] [- 1 1 -]
         */
        void cpl();

        /**
         * Set the carry flag.
         * scf          [1  |     4] [- 0 0 1]
         */
        void scf();

        /**
         * Take the complement of carry flag.
         * ccf          [1  |     4] [- 0 0 C]
         */
        void ccf();

        /************************\
        |* 16 Bit Load Ops      *|
        \************************/

        /**
         * Read 16 bits from the stack and store them in a 16 bit register.
         * ld_rr_nn     [3  |    12] [- - - -]
         *
         * @param hReg      [IN]        High byte of the register.
         * @param lReg      [IN]        Low byte of the register.
         */
        void ld_rr_nn(uint8 &hReg, uint8 &lReg);

        /**
         * Read 16 bits from the stack and store them in a 16 bit register.
         * ld_rr_nn     [3  |    12] [- - - -]
         *
         * @param reg       [IN]        The register.
         */
        void ld_rr_nn(uint16 &reg);

        /**
         * Read 16 bits from the stack and store them in a 16 bit register.
         * ld_nn_sp     [3  |    20] [- - - -]
         */
        void ld_nn_sp();

        /**
         * Store the contents of A into (HL) and increment HL.
         * ldi_hl_a     [1  |     8] [- - - -]
         */
        void ldi_hl_a();

        /**
         * Store the contents of (HL) into A and increment HL.
         * ldi_a_hl     [1  |     8] [- - - -]
         */
        void ldi_a_hl();

        /**
         * Store the contents of A into (HL) and deccrement HL.
         * ldd_hl_a     [1  |     8] [- - - -]
         */
        void ldd_hl_a();

        /**
         * Store the contents of (HL) into A and deccrement HL.
         * ldd_a_hl     [1  |     8] [- - - -]
         */
        void ldd_a_hl();

        /**
         * Store the contents of SP+N into HL.
         * ldhl_sp_n    [2  |    12] [- - - -]
         */
        void ldhl_sp_n();

        /**
         * Store the contents of HL into SP.
         * ld_sp_hl     [1  |     8] [- - - -]
         */
        void ld_sp_hl();

        /**
         * Pop 16 bits from stack into a register.
         * pop_rr       [1  |    12] [- - - -]
         *
         * @param hReg      [IN]        High byte of the register.
         * @param lReg      [IN]        Low byte of the register.
         */
        void pop_rr(uint8 &hReg, uint8 &lReg);

        /**
         * Push 16 bit register onto the stack.
         * push_rr      [1  |    12] [- - - -]
         *
         * @param hReg      [IN]        High byte of the register.
         * @param lReg      [IN]        Low byte of the register.
         */
        void push_rr(uint8 &hReg, uint8 &lReg);

        /************************\
        |* 16 Bit Arithmetic Ops*|
        \************************/

        /**
         * Increment the 16 bit register.
         * inc_rr       [1  |     8] [- - - -]
         *
         * @param hReg      [IN]        High byte of the register.
         * @param lReg      [IN]        Low byte of the register.
         */
        void inc_rr(uint8 &hReg, uint8 &lReg);

        /**
         * Increment the 16 bit register.
         * inc_rr       [1  |     8] [- - - -]
         *
         * @param reg       [IN]        The register.
         */
        void inc_rr(uint16 &reg);

        /**
         * Decrement the 16 bit register.
         * dec_rr       [1  |     8] [Z 0 H -]
         *
         * @param hReg      [IN]        High byte of the register.
         * @param lReg      [IN]        Low byte of the register.
         */
        void dec_rr(uint8 &hReg, uint8 &lReg);

        /**
         * Increment the 16 bit register.
         * dec_rr       [1  |     8] [- - - -]
         *
         * @param reg       [IN]        The register.
         */
        void dec_rr(uint16 &reg);

        /**
         * Add value in 16 bit register to HL.
         * add_hl_rr    [1  |     8] [- 0 H C]
         *
         * @param hReg      [IN]        High byte of the register.
         * @param lReg      [IN]        Low byte of the register.
         */
        void add_hl_rr(uint8 &hReg, uint8 &lReg);

        /**
         * Add value in 16 bit register to HL.
         * add_hl_rr    [1  |     8] [- 0 H C]
         *
         * @param reg       [IN]        The register.
         */
        void add_hl_rr(uint16 &reg);

        /**
         * Add one byte signed value to SP.
         * add_sp_n     [2  |    16] [0 0 H C]
         */
        void add_sp_n();

        /************************\
        |* CB Prefix Operations *|
        \************************/

        /**
         * Rotate register left. Old bit 7 to carry flag.
         * rlc_r        [2  |     8] [Z 0 0 C]
         *
         * @param reg       [IN]        Register to operate on.
         */
        void rlc_r(uint8 &reg);

        /**
         * Rotate (HL) left. Old bit 7 to carry flag.
         * rlc_hl       [2  |    16] [Z 0 0 C]
         */
        void rlc_hl();

        /**
         * Rotate register left through carry
         * rl_r         [2  |     8] [Z 0 0 C]
         *
         * @param reg       [IN]        Register to operate on.
         */
        void rl_r(uint8 &reg);

        /**
         * Rotate (HL) left through carry.
         * rl_hl        [2  |    16] [Z 0 0 C]
         */
        void rl_hl();

        /**
         * Rotate register right. Old bit 7 to carry flag.
         * rrc_r        [2  |     8] [Z 0 0 C]
         *
         * @param reg       [IN]        Register to operate on.
         */
        void rrc_r(uint8 &reg);

        /**
         * Rotate (HL) right. Old bit 7 to carry flag.
         * rrc_hl       [2  |    16] [Z 0 0 C]
         */
        void rrc_hl();

        /**
         * Rotate register right through carry
         * rr_r         [2  |     8] [Z 0 0 C]
         *
         * @param reg       [IN]        Register to operate on.
         */
        void rr_r(uint8 &reg);

        /**
         * Rotate (HL) right through carry.
         * rr_hl        [2  |    16] [Z 0 0 C]
         */
        void rr_hl();

        /**
         * Shift register left into carry. LSB set to 0.
         * sla_r        [2  |     8] [Z 0 0 C]
         *
         * @param reg       [IN]        Register to operate on.
         */
        void sla_r(uint8 &reg);

        /**
         * Shift (HL) left into carry. LSB set to 0.
         * sla_hl       [2  |    16] [Z 0 0 C]
         */
        void sla_hl();

        /**
         * Shift register right into carry. MSB unchanged.
         * sra_r        [2  |     8] [Z 0 0 0]
         *
         * @param reg       [IN]        Register to operate on.
         */
        void sra_r(uint8 &reg);

        /**
         * Shift (HL) right into carry. MSB set to 0.
         * sra_hl       [2  |    16] [Z 0 0 0]
         */
        void sra_hl();

        /**
         * Shift register right into carry. MSB set to 0.
         * srl_r        [2  |     8] [Z 0 0 C]
         *
         * @param reg       [IN]        Register to operate on.
         */
        void srl_r(uint8 &reg);

        /**
         * Shift (HL) right into carry. MSB set to 0.
         * srl_hl       [2  |    16] [Z 0 0 C]
         */
        void srl_hl();

        /**
         * Swap upper and lower nibbles of the register.
         * swap_r       [2  |     8] [Z 0 0 0]
         *
         * @param reg       [IN]        Register to operate on.
         */
        void swap_r(uint8 &reg);

        /**
         * Swap upper and lower nibbles of the register.
         * swap_hl      [2  |    16] [Z 0 0 0]
         */
        void swap_hl();

        /**
         * Test bit in a given register.
         * bit          [2  |     8] [Z 0 1 -]
         *
         * @param bit       [IN]        Bit position to operate on.
         * @param reg       [IN]        Register to operate on.
         */
        void bit_b_r(const uint8 bit, const uint8 &reg);

        /**
         * Test bit in (HL).
         * bit_hl       [2  |    16] [Z 0 1 -]
         *
         * @param bit       [IN]        Bit position to operate on.
         */
        void bit_b_hl(const uint8 bit);

        /**
         * Reset bit in a given register.
         * res          [2  |     8] [- - - -]
         *
         * @param bit       [IN]        Bit position to operate on.
         * @param reg       [IN]        Register to operate on.
         */
        void res_b_r(const uint8 bit, uint8 &reg);

        /**
         * Test bit in (HL).
         * res_hl       [2  |    16] [- - - -]
         *
         * @param bit       [IN]        Bit position to operate on.
         */
        void res_b_hl(const uint8 bit);

        /**
         * Set bit in a given register.
         * set          [2  |     8] [- - - -]
         *
         * @param bit       [IN]        Bit position to operate on.
         * @param reg       [IN]        Register to operate on.
         */
        void set_b_r(const uint8 bit, uint8 &reg);

        /**
         * Set bit in (HL).
         * set_hl       [2  |    16] [Z 0 1 -]
         *
         * @param bit       [IN]        Bit position to operate on.
         */
        void set_b_hl(const uint8 bit);

    private:
        /************************\
        |* Data Types           *|
        \************************/

        /* Registers in the cpu */
        struct _REGISTERS {
            uint8   a;  // Accumulator register
            uint8   f;  // Flags register: Bits [ZNHC0000]
            #define LR35902_FLAG_ZERO           (0x01 << 7)
            #define LR35902_FLAG_SUBTRACT       (0x01 << 6)
            #define LR35902_FLAG_HALF_CARRY     (0x01 << 5)
            #define LR35902_FLAG_CARRY          (0x01 << 4)
            uint8   b;  // b
            uint8   c;  // c
            uint8   d;  // d
            uint8   e;  // e
            uint8   h;  // h
            uint8   l;  // l

            uint16  sp; // Stack pointer
            uint16  pc; // Program Counter
        } r;
    };

} /* END: Nintendo */ } /* END: Processors */ } /* END: SiNES */
