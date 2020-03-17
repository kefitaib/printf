#include <stdarg.h>
#include "holberton.h"

/**
 * fillbuffer - fill the buffer with the parameters.
 * @format : composed of zero or more directives.
 * @form : strusture that contain fonctions.
 * @list : list of arguments.
 * @buffer : string to prints.
 * @k : index of the first empty case.
 * Return: void.
 */


int fillbuffer(const char *format, f_t form[], va_list list, char *buffer,
	       int *k)
{
	int i = 0, j, len = 0, *lenp = &len;

	while (format[i] != '\0')
	{
		for (; format[i] != '\0' && format[i] != '%'; i++, *k += 1)
		{
			if (*k == 1024)
				len += clearBuffer(buffer, k);
			buffer[*k] = format[i];
		}
		if (format[i] == '%')
		{
			i++;
			while (format[i] == ' ')
				i++;
			if (format[i] == '\0')
			{
				if (*k == 0)
					return (-1);
				return (len + *k);
			} j = 0;
			while (form[j].fo)
			{
				if (format[i] == *(form[j]).fo)
				{
					form[j].x(list, buffer, k, lenp);
					break;
				} j++;
			}
			if (!form[j].fo)
			{
				if (*k == 1024)
					len += clearBuffer(buffer, k);
				buffer[*k] = '%';
				*k += 1;
				if (*k == 1024)
					len += clearBuffer(buffer, k);
				buffer[*k] = format[i];
				*k += 1;
			}
		} i++;
	} return (len + *k);
}
