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

#ifndef UTILS_H_
#define UTILS_H_

	/**
	 * @brief Prints an error message and exits.
	 *
	 * @param msg Error message.
	 */
	extern void error(const char *msg);

	/**
	 * @brief Prints a debug message.
	 *
	 * @param msg Debug message.
	 */
	extern void  debug(const char *msg);

	/**
	 * @brief Converts an integer to a binary string.
	 *
	 * @param val Target value.
	 * @param str Target buffer to store resulting string.
	 *
	 * @returns A pointer to the resulting string.
	 */
	extern char *itoa2(int val, char *str, int base2);

	/**
	 * @brief Asserts a condition.
	 *
	 * @param x        Target condition.
	 * @param msg      Assert message.
	 * @param filename File name.
	 * @param linenum  Line number.
	 */
	extern void __checkfail(int x, const char *msg, const char *filename, int linenum);

	/**
	 * @see _check()
	 */
	#ifdef NDEBUG
	#define _check(x, msg) { ((void)(x)); ((void)(msg)); }
	#else
	#define _check(x, msg) __checkfail(x, msg, __FILE__, __LINE__)
	#endif

	/**
	 * @brief Asserts a condition.
	 *
	 * @param x Target condition.
	 */
	#define check(x) _check(x, "assert() failed")

#endif /* UTILS_H_ */
