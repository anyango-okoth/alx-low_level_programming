#include "main.h"
#include <limits.h>

/**
 * print_binary - Prints the binary equivalent of a decimal number.
 * @n: Number to print in binary.
 */
void print_binary(unsigned long int n)
{
	int i, j;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	for (i = 63; i >= 0; i--)
	{
		if (n & (1UL << i))
			break;
	}

	for (j = i; j >= 0; j--)
	{
		if (n & (1UL << j))
			_putchar('1');
		else
			_putchar('0');
	}
}

