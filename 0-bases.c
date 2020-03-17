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


/**
 * octalPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return: integer.
 */

int octalPrint(va_list l, char *buffer, int *k, int *len)
{
	unsigned int  x;
	int a[33];
	int i = 0, j = 0;

	x = va_arg(l, unsigned int);

	if (x == 0)
	{
		if (*k == 1024)
			*len += clearBuffer(buffer, k);
		buffer[*k] = 48;
		*k += 1;
	}

	while (x != 0)
	{
		a[i] = x % 8;
		x /= 8;
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


/**
 * hexaPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return: integer.
 */


int hexaPrint(va_list l, char *buffer, int *k, int *len)
{
	char tab[6] = "abcdef";
	char h[33];
	unsigned int  x;
	int j = 0, i = 0, index = 0;

	x = va_arg(l, unsigned int);

	if (x == 0)
	{
		if (*k == 1024)
			*len += clearBuffer(buffer, k);
		buffer[*k] = 48;
		*k += 1;
	}

	while (x != 0)
	{
		if ((x % 16) < 10)
			h[i] = (x % 16) + 48;
		else
		{
			index = (x % 16) % 10;
			h[i] = tab[index];
		}
		x /= 16;
		i++;
	}

	for (j = i - 1; j >= 0 ; j--, *k += 1)
	{
		if (*k == 1024)
			*len += clearBuffer(buffer, k);
		buffer[*k] = h[j];
	}
	return (0);
}



/**
 * hexaUpperPrint - append the buffer with the current parameter.
 * @l : list of arguments.
 * @buffer : string to prints.
 * @k : the current index  of the first empty element.
 * @len : length of the string to print.
 * Return: integer.
 */


int hexaUpperPrint(va_list l, char *buffer, int *k, int *len)
{
	char tab[6] = "ABCDEF";
	char h[33];
	unsigned int  x;
	int j = 0, i = 0, index = 0;

	x = va_arg(l, unsigned int);

	if (x == 0)
	{
		if (*k == 1024)
			*len += clearBuffer(buffer, k);
		buffer[*k] = 48;
		*k += 1;
	}

	while (x != 0)
	{
		if ((x % 16) < 10)
			h[i] = (x % 16) + 48;
		else
		{
			index = (x % 16) % 10;
			h[i] = tab[index];
		}
		x /= 16;
		i++;
	}

	for (j = i - 1; j >= 0 ; j--, *k += 1)
	{
		if (*k == 1024)
			*len += clearBuffer(buffer, k);
		buffer[*k] = h[j];
	}
	return (0);
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
				*k += 1;
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
				while (x < 4)
				{
					buffer[*k] = tab[x];
					*k += 1;
					x++;
				}
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
