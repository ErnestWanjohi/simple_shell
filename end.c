#include "simpleshell.h"


/**
 * find_char - finding character in a str
 * @string: string to search
 * @ch: the character
 * Return: NULL
 */
char *find_char(char *string, char ch)
{
	do {

		if (*string == ch)
		{
			return (string);
		}
	} while (*string++ != '\0');
	return (NULL);
}
/**
 * strncat_ - concatenates  strings
 * @dest: destination
 * @src: source
 * @x: num of chars
 * Return: char
 */
char *strncat_(char *dest, char *src, int x)
{
	char *ptr = dest;

	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*src != '\0' && x > 0)
	{
		*ptr = *src;
		ptr++;
		src++;
		x--;
	}
	*ptr = '\0';
	return (dest);
}
/**
 * stringncopy_ - copyssz str chars
 * @dest: dest fileeex
 * @src: source
 * @x:  chars
 * Return: dest tination 
 */
char *stringncopy_(char *dest, char *src, int x)
{
	char *ptr = dest;

	while (*src != '\0' && x > 0)
	{
		*dest = *src;
		dest++;
		src++;
		x--;
	}
	while (x > 0)
	{
		*dest = '\0';
		dest++;
		x--;
	}
	return (ptr);
}
