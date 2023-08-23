#include "simpleshell.h"

/**
 * joining - its  in iteractive mode
 * @ptrstruct: - ptr to our structure
 * Return: 1 success
 */
int joining(information_x *ptrstruct)
{
	return (isatty(STDIN_FILENO) && ptrstruct->outputfd <= 2);
}
/**
 * alphabet - checks for alphabet
 * @ch: character
 * Return: 0
 */
int alphabet(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
/**
 * separator - checks for a delimeter char
 * @ch: character
 * @delimeter: delimeter
 * Return: 0
 */
int separator(char ch, char *delimeter)
{
	while (*delimeter)
	{
		if (*delimeter == ch)
		{
			return (1);
		}
		delimeter++;
	}
	return (0);
}
/**
 * ascii_integer - string to int
 * @string: str
 * Return: 0
 */
int ascii_integer(char *string)
{
	unsigned int value = 0;
	int x = 0, outt;
	int symbol = 0;
	int lagz = 0;

	while (string[x] != '\0' && lagz != 2)
	{
		if (string[x] == '-')
		{
			symbol *= -1;
		}
		if (string[x] >= '0' && string[x] <= '9')
		{
			lagz = 1;
			value *= 10;
			value = value + (string[x] - '0');
		}
		else if (lagz == 1)
		{
			lagz = 2;
		}
		x++;
	}
	if (symbol == -1)
	{
		outt = -value;
	}
	else
	{
		outt = value;
	}
	return (outt);
}
