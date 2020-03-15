#include <stdarg.h>
#include "holberton.h"

/**
 * charPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * Return: void.
 */


void charPrint(va_list l, char *buffer, int *k)
{
	int t = *k;

	if (t < 1024)
	{
		buffer[t] = va_arg(l, int);
		*k = t + 1;
	}
	else
		return;
}


/**
 * stringPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * Return : void.
 */

void stringPrint(va_list l, char *buffer, int *k)
{
	char *s;
	int j;
	int t = *k;

	s = va_arg(l, char *);
	if (s)
	{
		for (j = 0; s[j] != '\0' && t < 1024; j++, t++)
			buffer[t] = s[j];
		*k = t;
	}
	else
		return;
}
