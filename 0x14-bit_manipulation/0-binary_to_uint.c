#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - converts a binary number to unsigned int
 * @b: string containing the binary number to be converted
 *
 * Return: the converted number or 0 if the number is not 0 or 1
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int value = 0;
	int i;

	if (b == NULL)
		return (0);

	for (i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0')
			value = value * 2;
		else if (b[i] == '1')
			value = value * 2 + 1;
		else
			return (0);
	}

	return (value);
}

