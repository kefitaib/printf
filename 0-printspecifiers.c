#include <stdarg.h>
#include "holberton.h"

/**
 * charPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return: void.
 */


void charPrint(va_list l, char *buffer, int *k, int *len)
{
	char c;

	if (*k == 1024)
		*len += clearBuffer(buffer, k);

	c = va_arg(l, int);
	if (c != NULL)
	{
		buffer[*k] = c;
		*k += 1;
	}
}


/**
 * stringPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return : void.
 */

void stringPrint(va_list l, char *buffer, int *k, int *len)
{
	char *s;
	int j;

	s = va_arg(l, char *);
	if (s)
	{
		for (j = 0 ; s[j] != '\0' ; j++, *k += 1)
		{
			if (*k == 1024)
				*len += clearBuffer(buffer, k);

			buffer[*k] = s[j];
		}
	}
}
