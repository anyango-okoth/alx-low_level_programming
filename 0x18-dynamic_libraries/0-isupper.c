#include "main.h"

/**
 * _isupper - checks int for uppercase
 * @c: number to be checked
 * Return: 0
 */

int _isupper(int c)
{
	if (c >= 65 && c <= 90)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
