#include "holberton.h"


/**
 * reverseStringPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return: integer.
 */

int reverseStringPrint(va_list l, char *buffer, int *k, int *len)
{
	char *s, str[6] = "(null)";
	int j = 0, i;

	s = va_arg(l, char *);
	if (s)
	{
		for (i = 0; s[i] != '\0'; i++)
			;
		for (j = i - 1; j >= 0; j--, *k += 1)
		{
			if (*k == 1024)
				*len += clearBuffer(buffer, k);

			buffer[*k] = s[j];
		}
		return (0);
	}
	for (j = 0 ; str[j] != '\0' ; j++, *k += 1)
	{
		if (*k == 1024)
			*len += clearBuffer(buffer, k);

		buffer[*k] = str[j];
	}
	return (-1);
}
