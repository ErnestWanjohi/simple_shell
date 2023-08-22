#include "simpleshell.h"

/**
 * output_error - outputs an error message
 * @ptrstruct: pointer to struct
 * @stringerror: stringerror
 */
void output_error(information_x *ptrstruct, char *stringerror)
{
	string_input(ptrstruct->fileidentity);
	string_input(": ");
	output_d(ptrstruct->band_length, STDERR_FILENO);
	string_input(":");
	string_input(ptrstruct->argvector[0]);
	string_input(":");
	string_input(stringerror);
}
/**
 * str_to_int - coverst strings to integers
 * @str: string given
 * Return: 1
 */
int str_to_int(char *str)
{
	unsigned long int value = 0;
	int i = 0;

	if (*str == '+')
	{
		str++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			value = value * 10;
			value = value + (str[i] - '0');
			if (value > INT_MAX)
			{
				return (-1);
			}
		}
		else
		{
			return (-1);
		}
		i++;
	}
	return (value);
}
/**
 * output_d - outputs decimal number
 * @value: our input
 * @FD: file descriptor
 * Return: counter of digigits
 */
int output_d(int value, int FD)
{
	int len = 0, x;

	unsigned int perfectvalue, now;
	int (*ptrchar)(char) = _putchar;

	if (FD == STDERR_FILENO)
	{
		ptrchar = putchar_error;
	}
	if (value < 0)
	{
		perfectvalue = -value;
		ptrchar('-');
		len++;
	}
	else
	{
		perfectvalue = value;
	}
	now = perfectvalue;
	x = 1000000000;
	while (x > 0)
	{
		if (perfectvalue / x)
		{
			ptrchar('0' + now / x);
			len++;
		}
		now %= x; /*now is current*/

		x /= 10;
	}
	ptrchar('0' + now);
	len++;

	return (len);
}
/**
 * eliminate_comments - adds a null to # symbol
 * @bufA: temp buffer for storage
 */
void eliminate_comments(char *bufA)
{
	int x;

	x = 0;
	while (bufA[x] != '\0')
	{
		if (bufA[x] == '#' && (!x || bufA[x - 1] == ' '))
		{
			bufA[x] = '\0';
			break;
		}
		x++;
	}
}
/**
 * change_num - changing or coverting number
 * @digit: numberr
 * @foundation: The base'
 * @flagz: the flags
 * Return: caracter
 */
char *change_num(long int digit, int foundation, int flagz)
{
	char symbol = 0;
	static char bufferA[50];
	static char *elements; /*array*/
	char *pointer;
	unsigned long x = digit;

	if (!(flagz & CHANGE_UNSYMBOL) && digit < 0)
	{
		x = -digit;
		symbol = '-';
	}
	elements = flagz & CHANGE_SMALL ? "0123456789abcdef"
	: "0123456789ABCDEF";
	pointer = &bufferA[49];
	*pointer = '\0';

	do {
		*--pointer = elements[x % foundation];
		x /= foundation;
	} while (x != 0);
	if (symbol)
	{
		*--pointer = symbol;
	}
	return (pointer);
}
