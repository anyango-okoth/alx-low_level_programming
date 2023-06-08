#include "main.h"

/**
 * get_bit - returns the value of a bit at an index in a decimal number
 * @n: number to search
 * @index: index/postion of the bit in the number
 *
 * Return: bit value or -1 if the bit position is invalid
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int shifted;
	unsigned long int bit;

	if (index >= sizeof(unsigned long int) * 8)
	{
		return (-1);
	}

	shifted = n >> index;
	bit = shifted & 1;

	return (bit);
}

