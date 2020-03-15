#include <stdarg.h>
#include "holberton.h"

/**
 * fillbuffer - fill the buffer with the parameters.
 * @format : composed of zero or more directives.
 * @form : strusture that contain fonctions.
 * @list : list of arguments.
 * @buffer : string to prints.
 * @kk : index of the first empty case.
 * Return: void.
 */


void fillbuffer(const char *format, f_t form[], va_list list, char *buffer,
int *kk)
{
	int k = *kk, i = 0, j, *m = &k;


	while (format[i] != '\0')
	{
		for (; format[i] != '\0' && k < 1024 &&
			     format[i] != '%'; i++, k++)
			buffer[k] = format[i];
		if (format[i] == '%')
		{
			if (format[i + 1] != '%')
			{
				j = 0;
				while (form[j].fo)
				{
					if (format[i + 1] == *(form[j]).fo)
					{
						form[j].x(list, buffer, m);
						i++;
						break;
					}
					j++;
				}
			}
			else
			{
				buffer[k] = '%';
				k++;
				i++;
			}
			i++;
		}
	}
	*kk = k;
}
