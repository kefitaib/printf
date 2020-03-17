#ifndef print
#define print
#include <stdarg.h>

/**
 * struct f - Struct f
 *
 * @fo: The operator
 * @x: The function associated
 */

typedef struct f
{
	char *fo;
	int (*x)(va_list, char *, int *, int *);
} f_t;

int clearBuffer(char *buffer, int *k);
int _printf(const char *format, ...);
int integerPrint(va_list l, char *buffer, int *k, int *len);
int charPrint(va_list l, char *buffer, int *k, int *len);
int stringPrint(va_list l, char *buffer, int *k, int *len);
int binaryPrint(va_list l, char *buffer, int *k, int *len);
int unsignedintPrint(va_list l, char *buffer, int *k, int *len);
int octalPrint(va_list l, char *buffer, int *k, int *len);
int hexaPrint(va_list l, char *buffer, int *k, int *len);
int hexaUpperPrint(va_list l, char *buffer, int *k, int *len);
int SsStringPrint(va_list l, char *buffer, int *k, int *len);
int reverseStringPrint(va_list l, char *buffer, int *k, int *len);
int percentPrint(va_list l, char *buffer, int *k, int *len);
int fillbuffer(const char *format, f_t form[], va_list list, char *buffer,
		int *kk);


#endif
