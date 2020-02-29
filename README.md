MIPS 32-Bit Instruction Decoder
================================

This is a simple decoder for MIPS 32-bit, that translates commands from
the assembly language to machine code.

The following instructions are supported:

- R Type: `add`,  `sub`,  `mult`,  `div`,  `and`,  `or`,  `xor`,  `nor`,  `slt`,  `sll`,  `srl`,  `jr`

- I Type: `addi`,  `andi`,  `ori`,  `slti`,  `lw`,  `sw`,  `beq`, `bne`

- J Type: `j`,  `jal`
