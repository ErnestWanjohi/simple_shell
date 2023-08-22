#include "simpleshell.h"

/**
 * length_string - returns string length
 * @sl: the string's length
 * Return: integer extent
 */
int length_string(char *sl)
{
	int m = 0;

	if (!sl)
		return (0);

	while (*sl++)
		m++;
	return (m);
}

/**
 * comparison - performs string comparison
 * @sl1:  string one
 * @sl2: second strang to compare with
 * Return: negative if sl1 is shrter than sl2
 *  positive if sl1 is longer than sl2, zero if equal
 */
int comparison(char *sl1, char *sl2)
{
	while (*sl1 && *sl2)
	{
		if (*sl1 != *sl2)
			return (*sl1 - *sl2);
		sl1++;
		sl2++;
	}
	if (*sl1 == *sl2)
		return (0);
	else
		return (*sl1 < *sl2 ? -1 : 1);
}

/**
 * begin - checks if needle begins with haystack
 * @hay_stack: string to search
 * @nidle: substring to check
 * Return: address of next char of haystack or NULL
 */
char *begin(const char *hay_stack, const char *nidle)
{
	while (*nidle)
		if (*nidle++ != *hay_stack++)
			return (NULL);
	return ((char *)hay_stack);
}

/**
 * concatenation - concatenates two strings
 * @destination: destination buffer
 * @source: buffer source
 * Return: destination buffer
 */
char *concatenation(char *destination, char *source)
{
	char *x = destination;

	while (*destination)
		destination++;
	while (*source)
		*destination++ = *source++;
	*destination = *source;
	return (x);
}
