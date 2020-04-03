/*
 * MIT License
 *
 * Copyright(c) 2020 Pedro Henrique Penna <pedrohenriquepenna@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <mips32/inst.h>
#include <mips32/utils.h>
#include <mips32/regs.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Forward definitions. */
extern struct inst instructions[];
extern struct reg registers[];

/**
 * @brief Del imitating characters.
 */
const char *delim = " ,()";

/**
 * @brief Lookups the code of a register.
 *
 * @param regname Name of the target register.
 *
 * @returns Upon successful completion the code of the requested
 * register is returned. Upon failure, a null pointer is returned
 * instead.
 */
static const char *register_lookup(const char *regname)
{
	if (regname == NULL)
		return (NULL);

	for (int i = 0; i < REG_NUM; i++)
	{
		if (!strcmp(registers[i].name, regname))
			return (registers[i].code);
	}

	return (NULL);
}

/**
 * @brief Lookups the operation code of an instruction.
 *
 * @param inst Name of the target instruction
 *
 * @returns Upon successful completion the operation code of the
 * requested instruction is returned. Upon failure, a null pointer is
 * returned instead.
 */
static const char *opcode_lookup(const char *inst)
{
	if (inst == NULL)
		return (NULL);

	for (int i = 0; instructions[i].name != NULL; i++)
	{
		if (!strcmp(instructions[i].name, inst))
			return (instructions[i].opcode);
	}

	return (NULL);
}


/**
 * @brief Lookups the function code of an instruction.
 *
 * @param inst Name of the target instruction
 *
 * @returns Upon successful completion the function code of the
 * requested instruction is returned. Upon failure, a null pointer is
 * returned instead.
 */
static const char *funct_lookup(const char *cmd)
{
	if (cmd == NULL)
		return (NULL);

	for (int i = 0; instructions[i].name != NULL; i++)
	{
		if (!strcmp(instructions[i].name, cmd))
			return (instructions[i].funct);
	}

	return (NULL);
}

/*============================================================================*
 * R Instructions                                                             *
 *============================================================================*/

/**
 * @brief Encodes a generic R instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_r_instruction(FILE *output, const char *inst)
{
	const char *rd;
	const char *rs;
	const char *rt;
	const char *opcode;
	const char *funct;

	check((rd = register_lookup(strtok(NULL, delim))) != NULL);
	check((rs = register_lookup(strtok(NULL, delim))) != NULL);
	check((rt = register_lookup(strtok(NULL, delim))) != NULL);
	check((opcode = opcode_lookup(inst)) != NULL);
	check((funct = funct_lookup(inst)) != NULL);

	fprintf(output, "%s%s%s%s%s%s\n",
		opcode,
		rs,
		rt,
		rd,
		"00000",
		funct
	);
}

/**
 * @brief Encodes an ADD instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_add(FILE *output, const char *inst)
{
	encode_r_instruction(output, inst);
}

/**
 * @brief Encodes a SUB instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_sub(FILE *output, const char *inst)
{
	encode_r_instruction(output, inst);
}

/**
 * @brief Encodes a MULT instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_mult(FILE *output, const char *inst)
{
	const char *rs;
	const char *rt;
	const char *opcode;
	const char *funct;

	check((rs = register_lookup(strtok(NULL, delim))) != NULL);
	check((rt = register_lookup(strtok(NULL, delim))) != NULL);
	check((opcode = opcode_lookup(inst)) != NULL);
	check((funct = funct_lookup(inst)) != NULL);

	fprintf(output, "%s%s%s%s%s%s\n",
		opcode,
		rs,
		rt,
		"00000",
		"00000",
		funct
	);
}

/**
 * @brief Encodes a DIV instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_div(FILE *output, const char *inst)
{
	const char *rs;
	const char *rt;
	const char *opcode;
	const char *funct;

	check((rs = register_lookup(strtok(NULL, delim))) != NULL);
	check((rt = register_lookup(strtok(NULL, delim))) != NULL);
	check((opcode = opcode_lookup(inst)) != NULL);
	check((funct = funct_lookup(inst)) != NULL);

	fprintf(output, "%s%s%s%s%s%s\n",
		opcode,
		rs,
		rt,
		"00000",
		"00000",
		funct
	);
}

/**
 * @brief Encodes an AND instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_and(FILE *output, const char *inst)
{
	encode_r_instruction(output, inst);
}

/**
 * @brief Encodes an OR instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_or(FILE *output, const char *inst)
{
	encode_r_instruction(output, inst);
}

/**
 * @brief Encodes a XOR instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_xor(FILE *output, const char *inst)
{
	encode_r_instruction(output, inst);
}

/**
 * @brief Encodes a NOR instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_nor(FILE *output, const char *inst)
{
	encode_r_instruction(output, inst);
}

/**
 * @brief Encodes a SLT instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_slt(FILE *output, const char *inst)
{
	encode_r_instruction(output, inst);
}

/**
 * @brief Encodes a SLL instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_sll(FILE *output, const char *inst)
{
	const char *rd;
	const char *rt;
	const char *opcode;
	const char *funct;
	const char *shamt10;
	char shamt2[33];

	check((rd = register_lookup(strtok(NULL, delim))) != NULL);
	check((rt = register_lookup(strtok(NULL, delim))) != NULL);
	check((shamt10 = strtok(NULL, delim)) != NULL);
	check((opcode = opcode_lookup(inst)) != NULL);
	check((funct = funct_lookup(inst)) != NULL);

	itoa2(atoi(shamt10), shamt2, 2);

	fprintf(output, "%s%s%s%s%s%s\n",
		opcode,
		"00000",
		rt,
		rd,
		&shamt2[27],
		funct
	);
}

/**
 * @brief Encodes a SRL instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_srl(FILE *output, const char *inst)
{
	const char *rd;
	const char *rt;
	const char *opcode;
	const char *funct;
	const char *shamt10;
	char shamt2[33];

	check((rd = register_lookup(strtok(NULL, delim))) != NULL);
	check((rt = register_lookup(strtok(NULL, delim))) != NULL);
	check((shamt10 = strtok(NULL, delim)) != NULL);
	check((opcode = opcode_lookup(inst)) != NULL);
	check((funct = funct_lookup(inst)) != NULL);

	itoa2(atoi(shamt10), shamt2, 2);

	fprintf(output, "%s%s%s%s%s%s\n",
		opcode,
		"00000",
		rt,
		rd,
		&shamt2[27],
		funct
	);
}

/**
 * @brief Encodes a JR instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_jr(FILE *output, const char *inst)
{
	const char *rs;
	const char *opcode;
	const char *funct;

	check((rs = register_lookup(strtok(NULL, delim))) != NULL);
	check((opcode = opcode_lookup(inst)) != NULL);
	check((funct = funct_lookup(inst)) != NULL);

	fprintf(output, "%s%s%s%s%s%s\n",
		opcode,
		rs,
		"00000",
		"00000",
		"00000",
		funct
	);
}

/*============================================================================*
 * I Instructions                                                             *
 *============================================================================*/

/**
 * @brief Encodes a generic I instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_i_instruction(FILE *output, const char *inst)
{
	const char *rt;
	const char *rs;
	const char *opcode;
	const char *branch10;
	char branch2[33];

	check((rt = register_lookup(strtok(NULL, delim))) != NULL);
	check((rs = register_lookup(strtok(NULL, delim))) != NULL);
	check((branch10 = strtok(NULL, delim)) != NULL);
	check((opcode = opcode_lookup(inst)) != NULL);

	itoa2(atoi(branch10), branch2, 2);

	fprintf(output, "%s%s%s%s\n",
		opcode,
		rs,
		rt,
		&branch2[16]
	);
}

/**
 * @brief Encodes an ADDI instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_addi(FILE *output, const char *inst)
{
	encode_i_instruction(output, inst);
}

/**
 * @brief Encodes an ANDI instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_andi(FILE *output, const char *inst)
{
	encode_i_instruction(output, inst);
}

/**
 * @brief Encodes an ORI instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_ori(FILE *output, const char *inst)
{
	encode_i_instruction(output, inst);
}

/**
 * @brief Encodes an SLTI instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_slti(FILE *output, const char *inst)
{
	encode_i_instruction(output, inst);
}

/**
 * @brief Encodes an BEQ instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_beq(FILE *output, const char *inst)
{
	encode_i_instruction(output, inst);
}

/**
 * @brief Encodes an BNE instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_bne(FILE *output, const char *inst)
{
	encode_i_instruction(output, inst);
}

/**
 * @brief Encodes an LW instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_lw(FILE *output, const char *inst)
{
	const char *rt;
	const char *rs;
	const char *opcode;
	const char *branch10;
	char branch2[33];

	check((rt = register_lookup(strtok(NULL, delim))) != NULL);
	check((branch10 = strtok(NULL, delim)) != NULL);
	check((rs = register_lookup(strtok(NULL, delim))) != NULL);
	check((opcode = opcode_lookup(inst)) != NULL);

	itoa2(atoi(branch10), branch2, 2);

	fprintf(output, "%s%s%s%s\n",
		opcode,
		rs,
		rt,
		&branch2[16]
	);
}

/**
 * @brief Encodes an SW instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_sw(FILE *output, const char *inst)
{
	const char *rt;
	const char *rs;
	const char *opcode;
	const char *branch10;
	char branch2[33];

	check((rt = register_lookup(strtok(NULL, delim))) != NULL);
	check((branch10 = strtok(NULL, delim)) != NULL);
	check((rs = register_lookup(strtok(NULL, delim))) != NULL);
	check((opcode = opcode_lookup(inst)) != NULL);

	itoa2(atoi(branch10), branch2, 2);

	fprintf(output, "%s%s%s%s\n",
		opcode,
		rs,
		rt,
		&branch2[16]
	);
}

/*============================================================================*
 * J Instructions                                                             *
 *============================================================================*/

/**
 * @brief Encodes a generic J instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_j_instruction(FILE *output, const char *inst)
{
	const char *opcode;
	const char *addr10;
	char addr2[33];

	check((addr10 = strtok(NULL, delim)) != NULL);
	check((opcode = opcode_lookup(inst)) != NULL);

	itoa2(atoi(addr10), addr2, 2);

	fprintf(output, "%s%s\n",
		opcode,
		&addr2[7]
	);
}

/**
 * @brief Encodes a J instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_j(FILE *output, const char *inst)
{
	encode_j_instruction(output, inst);
}

/**
 * @brief Encodes a JAL instruction.
 *
 * @param output Output file.
 * @param inst   Target instruction.
 */
static void encode_jal(FILE *output, const char *inst)
{
	encode_j_instruction(output, inst);
}

/*============================================================================*
 * encode()                                                                   *
 *============================================================================*/

/**
 * @brief Lookup table of registers.
 */
struct reg registers[REG_NUM] = {
	{ REG_ZERO_NUM_STR, REG_ZERO_NAME },
	{ REG_AT_NUM_STR,   REG_AT_NAME   },
	{ REG_V0_NUM_STR,   REG_V0_NAME   },
	{ REG_V1_NUM_STR,   REG_V1_NAME   },
	{ REG_A0_NUM_STR,   REG_A0_NAME   },
	{ REG_A1_NUM_STR,   REG_A1_NAME   },
	{ REG_A2_NUM_STR,   REG_A2_NAME   },
	{ REG_A3_NUM_STR,   REG_A3_NAME   },
	{ REG_T0_NUM_STR,   REG_T0_NAME   },
	{ REG_T1_NUM_STR,   REG_T1_NAME   },
	{ REG_T2_NUM_STR,   REG_T2_NAME   },
	{ REG_T3_NUM_STR,   REG_T3_NAME   },
	{ REG_T4_NUM_STR,   REG_T4_NAME   },
	{ REG_T5_NUM_STR,   REG_T5_NAME   },
	{ REG_T6_NUM_STR,   REG_T6_NAME   },
	{ REG_T7_NUM_STR,   REG_T7_NAME   },
	{ REG_S0_NUM_STR,   REG_S0_NAME   },
	{ REG_S1_NUM_STR,   REG_S1_NAME   },
	{ REG_S2_NUM_STR,   REG_S2_NAME   },
	{ REG_S3_NUM_STR,   REG_S3_NAME   },
	{ REG_S4_NUM_STR,   REG_S4_NAME   },
	{ REG_S5_NUM_STR,   REG_S5_NAME   },
	{ REG_S6_NUM_STR,   REG_S6_NAME   },
	{ REG_S7_NUM_STR,   REG_S7_NAME   },
	{ REG_T8_NUM_STR,   REG_T8_NAME   },
	{ REG_T9_NUM_STR,   REG_T9_NAME   },
	{ REG_K0_NUM_STR,   REG_K0_NAME   },
	{ REG_K1_NUM_STR,   REG_K1_NAME   },
	{ REG_GP_NUM_STR,   REG_GP_NAME   },
	{ REG_SP_NUM_STR,   REG_SP_NAME   },
	{ REG_FP_NUM_STR,   REG_FP_NAME   },
	{ REG_RA_NUM_STR,   REG_RA_NAME   },
};

/**
 * @brief Lookup table of instructions.
 */
struct inst instructions[] = {
	{ INST_NAME_ADD,  INST_ADD_OPCODE_STR,  INST_ADD_FUNCT_STR,  encode_add  },
	{ INST_NAME_ADDI, INST_ADDI_OPCODE_STR, "",                  encode_addi },
	{ INST_NAME_SUB,  INST_SUB_OPCODE_STR,  INST_SUB_FUNCT_STR,  encode_sub  },
	{ INST_NAME_MULT, INST_MULT_OPCODE_STR, INST_MULT_FUNCT_STR, encode_mult },
	{ INST_NAME_DIV,  INST_DIV_OPCODE_STR,  INST_DIV_FUNCT_STR,  encode_div  },
	{ INST_NAME_AND,  INST_AND_OPCODE_STR,  INST_AND_FUNCT_STR, encode_and   },
	{ INST_NAME_ANDI, INST_ANDI_OPCODE_STR, "",                 encode_andi  },
	{ INST_NAME_OR,   INST_OR_OPCODE_STR,   INST_OR_FUNCT_STR,  encode_or    },
	{ INST_NAME_ORI,  INST_ORI_OPCODE_STR,  "",                 encode_ori   },
	{ INST_NAME_XOR,  INST_XOR_OPCODE_STR,  INST_XOR_FUNCT_STR, encode_xor   },
	{ INST_NAME_NOR,  INST_NOR_OPCODE_STR,  INST_NOR_FUNCT_STR, encode_nor   },
	{ INST_NAME_SLT,  INST_SLT_OPCODE_STR,  INST_SLT_FUNCT_STR, encode_slt   },
	{ INST_NAME_SLTI, INST_SLTI_OPCODE_STR, "",                 encode_slti  },
	{ INST_NAME_SLL,  INST_SLL_OPCODE_STR,  INST_SLL_FUNCT_STR, encode_sll   },
	{ INST_NAME_SRL,  INST_SRL_OPCODE_STR,  INST_SRL_FUNCT_STR, encode_srl   },
	{ INST_NAME_LW,   INST_LW_OPCODE_STR,   "",                 encode_lw    },
	{ INST_NAME_SW,   INST_SW_OPCODE_STR,   "",                 encode_sw    },
	{ INST_NAME_BEQ,  INST_BEQ_OPCODE_STR,  "",                 encode_beq   },
	{ INST_NAME_BNE,  INST_BNE_OPCODE_STR,  "",                 encode_bne   },
	{ INST_NAME_J,    INST_J_OPCODE_STR,    "",                 encode_j     },
	{ INST_NAME_JR,   INST_JR_OPCODE_STR,   INST_JR_FUNCT_STR,  encode_jr    },
	{ INST_NAME_JAL,  INST_JAL_OPCODE_STR,  "",                 encode_jal   },
	{ NULL,           NULL,                NULL,                NULL         },
};

/**
 * @brief Encodes an assembly file
 */
void encode(FILE *output, FILE *input)
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;

	/* Read input file. */
	while ((nread = getline(&line, &len, input)) != -1)
	{
		int unkown = 1;
		char *token;

		/* Remove newline. */
		line[nread - 1] = '\0';

		/* Parse line. */
		debug(line);
		if ((token = strtok(line, delim)) == NULL)
			break;

		/* Lookup instruction. */
		for (int j = 0; instructions[j].encode != NULL; j++)
		{
			/* Encode instruction.*/
			if (!strcmp(token, instructions[j].name))
			{
				unkown = 0;
				instructions[j].encode(output, token );
				break;
			}
		}

		if (unkown)
			error("unknown command");
	}

	/* House keeping. */
	free(line);
}
