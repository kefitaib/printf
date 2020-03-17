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


/**
 * rot13 - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return: integer.
 */

int rot13(va_list l, char *buffer, int *k, int *len)
{
	char s1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char s2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int i = 0, j;
	char *s, str[6] = "(null)";

	s = va_arg(l, char *);
	if (s)
	{
		while (s[i] != '\0')
		{
			j = 0;
			while (j < 52 && s[i] != s1[j])
				j++;
			if (j < 52)
			{
				if (*k == 1024)
					*len += clearBuffer(buffer, k);
				buffer[*k] = s2[j];
				*k += 1;
				i++;
			}
			else
			{
				if (*k == 1024)
					*len += clearBuffer(buffer, k);
				buffer[*k] = s[i];
				*k += 1;
				i++;
			}
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
 * SsStringPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return: integer.
 */


int SsStringPrint(va_list l, char *buffer, int *k, int *len)
{
	char *s, str[6] = "(null)";
	int j, x = 0, n, i;
	char hex[] = "0123456789ABCDEF", tab[] = {92, 'x', '0', '0'};

	s = va_arg(l, char *);
	if (s)
	{
		for (j = 0 ; s[j] != '\0' ; j++, *k += 1)
		{
			if (*k == 1024)
				*len += clearBuffer(buffer, k);
			if (s[j] >= 32 && s[j] < 127)
			{
				buffer[*k] = s[j];
			} else
			{
				n = s[j];
				i = 3;
				while (n != 0)
				{
					tab[i] = hex[n % 16];
					n /= 16;
					i--;
				}
				for (x = 0; x < 4; x++, *k += 1)
				{
					buffer[*k] = tab[x];
					if (*k == 1024)
						*len += clearBuffer(buffer, k);
				} *k -= 1;
			}
		} return (0);
	}
	for (j = 0 ; str[j] != '\0' ; j++, *k += 1)
	{
		if (*k == 1024)
			*len += clearBuffer(buffer, k);
		buffer[*k] = str[j];
	} return (-1);
}
