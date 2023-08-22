#include "simpleshell.h"

/**
 * stringduplicate - duplicates  string
 * @station: place to duplicate
 * @source:  place to extract
 * Return: pointer to destination
 */
char *stringduplicate(char *station, char *source)
{
	int g = 0;

	if (station == source || source == 0)
		return (station);
	for (int g = 0; source[g]; g++)
	{
		station[g] = source[g];
	}
	station[g] = 0;
	return (station);
}

/**
 * string_duplicator - duplicator
 * @string: one to duplicate
 * Return: duplicated string
 */
char *string_duplicator(const char *string)
{
	int extent = 0;
	char *mlc;

	if (string == NULL)
		return (NULL);
	while (*string++)
		extent++;
	mlc = malloc(sizeof(char) * (extent + 1));
	if (!mlc)
		return (NULL);
	for (extent++; extent--;)
		mlc[extent] = *--string;
	return (mlc);
}

/**
 * _puts - outputs string
 * @stringA: one to output
 * Return: success
 */
void _puts(char *stringA)
{
	int l = 0;

	if (!stringA)
		return;
	while (stringA[l] != '\0')
	{
		_putchar(stringA[l]);
		l++;
	}
}

/**
 * _putchar - c to stdout.
 * @ch: pint character
 * Return: 1 On success,
 * else err -1
 */
int _putchar(char ch)
{
	static int v;
	static char buffA[OUTPUT_BUFFER_LEN];

	if (ch == EMPTY_BUFFER || v >= OUTPUT_BUFFER_LEN)
	{
		write(1, buffA, v);
		v = 0;
	}
	if (ch != EMPTY_BUFFER)
		buffA[v++] = ch;
	return (1);
}
