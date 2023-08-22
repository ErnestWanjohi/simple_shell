#include "simpleshell.h"



/**
 * putchar_error - writes the chaar to std error
 * @ch: the character
 * Return: 1
 */
int putchar_error(char ch)
{
	static char bufferA[OUTPUT_BUFFER_LEN];
	static int xx;

	if (ch == EMPTY_BUFFER || xx >= OUTPUT_BUFFER_LEN)
	{
		write(2, bufferA, xx);
		xx = 0;
	}
	if (ch != EMPTY_BUFFER)
	{
		bufferA[xx++] = ch;
	}
	return (1);
}

/**
 * string_input - writes a string input
 * @string: the spec string
 */
void string_input(char *string)
{
	int y;

	y = 0;

	if (!string)
	{
		return;
	}
	while (string[y] != '\0')
	{
		putchar_error(string[y]);
		y++;
	}
}
/**
 * write_str_fd - string to file desrciptor
 * @string: stringg
 * @FD: file descriptor
 * Return: q
 */
int write_str_fd(char *string, int FD)
{
	int q = 0;

	if (!string)
	{
		return (0);
	}
	while (*string)
	{
		q = q + write_fd(*string++, FD);
	}
	return (q);
}

/**
 * write_fd - writes a char to a file descriptor
 * @ch: character
 * @FD: file descriptor
 * Return: 1
 */
int write_fd(char ch, int FD)
{
	static char bufA[OUTPUT_BUFFER_LEN];
	static int q;

	if (ch == EMPTY_BUFFER || q >= OUTPUT_BUFFER_LEN)
	{
		write(FD, bufA, q);
		q = 0;
	}
	if (ch != EMPTY_BUFFER)
	{
		bufA[q++] = ch;

	}
	return (1);
}
