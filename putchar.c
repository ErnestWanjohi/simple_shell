#include "simpleshell.h"
#include <unistd.h>
/**
 * _putchar - writes the character
 * @f: character to output
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char f)
{
	return (write(1, &f, 1));
}
