#include <stdarg.h>
#include "holberton.h"

/**
 * percentPrint- append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return: integer.
 */



int percentPrint(va_list l, char *buffer, int *k, int *len)
{
	va_list lst;

	va_copy(lst, l);
	va_arg(lst, void *);

	if (*k == 1024)
		*len += clearBuffer(buffer, k);

	buffer[*k] = '%';
	*k += 1;
	va_end(lst);
	return (0);
}



/**
 * charPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return: integer.
 */


int charPrint(va_list l, char *buffer, int *k, int *len)
{
	char c;

	if (*k == 1024)
		*len += clearBuffer(buffer, k);

	c = va_arg(l, int);
	if (c)
	{
		buffer[*k] = c;
		*k += 1;
		return (0);
	}
	return (-1);
}


/**
 * stringPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return: integer.
 */

int stringPrint(va_list l, char *buffer, int *k, int *len)
{
	char *s, str[6] = "(null)";
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


/**
 * integerPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return: integer.
 */

int integerPrint(va_list l, char *buffer, int *k, int *len)
{
	char s[10];
	int i = 0, j, n, n2, tmp = 0;

	n = va_arg(l, int);

	n2 = n;

	if (n == -2147483648)
		tmp = 1;

	if (n < 0)
		n = -(n + tmp);

	do {
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	} while (n > 0);

	s[0] = ((s[0] - '0') + tmp) + '0';

	if (n2 < 0)
	{
		if (*k == 1024)
			*len += clearBuffer(buffer, k);
		buffer[*k] = '-';
		*k += 1;
	}

	for (j = i - 1; j >= 0; j--, *k += 1)
	{
		if (*k == 1024)
			*len += clearBuffer(buffer, k);
		buffer[*k] = s[j];
	}
	return (0);
}
