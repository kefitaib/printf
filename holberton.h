#ifndef pri
#define pri
#include <stdarg.h>
#include <stdio.h>

/**
 * struct f - Struct f
 *
 * @fo: The operator
 * @x: The function associated
 */

typedef struct f
{
	char *fo;
	void (*x)(va_list, char *, int *);
} f_t;

int _printf(const char *format, ...);
void charPrint(va_list l, char *buffer, int *k);
void stringPrint(va_list l, char *buffer, int *k);
void fillbuffer(const char *format, f_t form[], va_list list, char *buffer,
		int *kk);


#endif
