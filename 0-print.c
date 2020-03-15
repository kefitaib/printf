#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include "holberton.h"

/**
 * _printf - print anything.
 * @format : string of directives.
 * Return: number of caracters printed.
 */


int _printf(const char *format, ...)
{
	va_list list;
	int k = 0, *kk = &k;
	char *buffer;
	f_t form[] = {
		{"c", charPrint},
		{"s", stringPrint},
		{NULL, NULL}
	};


	if (!format)
		return (-1);
	va_start(list, format);
	buffer = malloc(1024);
	if (!buffer)
		return (-1);
	fillbuffer(format, form, list, buffer, kk);
	write(1, buffer, k);
	free(buffer);
	va_end(list);
	return (k);
}
