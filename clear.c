#include <unistd.h>

/**
 * clearBuffer - clear the buffer.
 * @buffer : string to prints.
 * @k : index of the first empty case.
 * Return: buffer size.
 */

int clearBuffer(char *buffer, int *k)
{
	write(1, buffer, 1024);
	*k = 0;
	return (1024);
}
