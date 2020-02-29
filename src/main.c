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

#include <mips32/utils.h>
#include <stdio.h>
#include <stdlib.h>

/* Import definitions. */
extern void encode(FILE *output, FILE *input);

/**
 * @brief Prints program usage and exits.
 */
static void usage(void)
{
	fprintf(stderr, "mips-decode [input] [output]\n");
	exit(EXIT_FAILURE);
}

/**
 * @brief Parses command-line arguments.
 *
 * @param argc Argument count.
 * @param argv Argument list.
 *
 * @returns Upon successful completion EXIT_SUCCESS is returned,
 * otherwise EXIT_FAILURE is returned instead.
 */
int main(int argc, const char *argv[])
{
	const char *errorstr; /* Error string.       */
	FILE *input, *output; /* Input/output files. */

	input = stdin;
	output = stdout;

	/* Missing arguments? */
	if (argc > 3)
		usage();

	if (argc == 3)
	{
		/* Cannot open input file. */
		if ((input = fopen(argv[1], "r")) == NULL)
		{
			errorstr = "cannot open input file";
			goto error0;
		}

		if ((output = fopen(argv[2], "w")) == NULL)
		{
			errorstr = "cannot create output file";
			goto error1;
		}
	}

	encode(output, input);

	/* House keeping. */
	fclose(input);
	fclose(output);

	return (EXIT_SUCCESS);

error1:
	fclose(input);
error0:
	error(errorstr);
	return (EXIT_FAILURE);
}
