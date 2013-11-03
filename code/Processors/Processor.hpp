#include "xplat/types.hpp"

namespace SiNES { namespace Processors {
    /**
     * The Abstract Processor class.
     */
    class Processor {
    public:
        /**
         * Constructor for an LR35902 processor.
         */
        Processor();

        /**
         * Destructor for an LR35902 processor.
         */
        virtual ~Processor();

        /**
         * Execute the next processor level operation.
         */
        virtual void execOp() = 0;

    protected:
        /************************************************\
        |* Op Code Functions                            *|
        \************************************************/
        virtual void INVALID_OP();

    private:
    };

} /* END: Processors */ } /* END: SiNES */
