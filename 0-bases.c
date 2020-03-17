#include <stdarg.h>
#include "holberton.h"

/**
 * binaryPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return: integer.
 */


int binaryPrint(va_list l, char *buffer, int *k, int *len)
{

	unsigned int  x;
	int a[33];
	int i = 0, j = 0;

	x = va_arg(l, unsigned int);

	if (x == 0)
	{
		if (*k == 1024)
			*len += clearBuffer(buffer, k);
		buffer[*k] = 0 + 48;
		*k += 1;
	}

	while (x != 0)
	{
		a[i] = x % 2;
		x /= 2;
		i++;
	}

	for (j = i - 1 ; j >= 0 ; j--, *k += 1)
	{
		if (*k == 1024)
			*len += clearBuffer(buffer, k);
		buffer[*k]  = a[j] + 48;

	}

	return  (0);
}
