#include "main.h"

/**
 * clear_bit - sets the value of a given bit to 0
 * @n: pointer to the unsigned long int
 * @index: postion of the bit to clear
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(unsigned long) * 8)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}

