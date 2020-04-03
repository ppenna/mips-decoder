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

#include <stdio.h>
#include <stdlib.h>

/*============================================================================*
 * error()                                                                    *
 *============================================================================*/

/**
 * @brief Prints an error message and exits.
 *
 * @param msg Error message.
 */
void error(const char *msg)
{
	fprintf(stderr, "%s\n", msg);

	exit(EXIT_FAILURE);
}

/*============================================================================*
 * debug()                                                                    *
 *============================================================================*/

/**
 * The debug() function prints a debug message in the standard output
 * error.
 */
void debug(const char *msg)
{
#ifndef NDEBUG
	fprintf(stderr, "%s\n", msg);
#else
	((void) msg);
#endif
}

/*============================================================================*
 * itoa2()                                                                    *
 *============================================================================*/

/**
 * @brief Reverses a string.
 *
 * @param str Target string.
 * @param len Length of the target string.
 */
static void reverse(char *str, int len)
	{
	int start = 0;
	int end = len -1;
	while (start < end)
	{
		char tmp;

		tmp = *(str+start);
		*(str+start) = *(str+end);
		*(str+end) = tmp;

		start++;
		end--;
	}
}

/**
 * Converts an integer value to a null-terminated string using the
 * binary base and stores the result in the array given by @p str
 * parameter.
 */
char *itoa2(int val, char *str)
{
	int i = 0;
	int isNegative = 0;

	/* Handle 0 explicitely, otherwise empty string is printed for 0 */
	if (val == 0)
	{
		for ( ; i < 32; i++)
			str[i] = '0';
		str[i] = '\0';
		return str;
	}

	while (val != 0)
	{
		int rem = val % 2;
		str[i++] = rem + '0';
		val = val/2;
	}

	if (isNegative)
		str[i++] = '-';

	for ( ; i < 32; i++)
		str[i] = '0';

	str[i] = '\0';

	reverse(str, i);

	return str;
}

/*============================================================================*
 * __checkfail()                                                              *
 *============================================================================*/

/**
 * The __checkfail() asserts a condition.
 */
void __checkfail(int x, const char *msg, const char *filename, int linenum)
{
	if (!x)
	{
		fprintf(stderr, "%s: %s %d\n", msg, filename, linenum);
		exit(EXIT_FAILURE);
	}
}
