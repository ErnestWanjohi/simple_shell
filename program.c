#include "simpleshell.h"
/**
 * main - entry
 * @counter: counter len
 * @vector: vector arg
 * Return: 1 or 0
 */
int main(int counter, char **vector)
{
	information_x ptrstruct[] = { CONFIG_STRUCT };
	int x  = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (x)
			: "r" (x));

	if (counter == 2)
	{
		x = open(vector[1], O_RDONLY);
		if (x == -1)
		{
			if (errno == EACCES)
				exit(98);
			if (errno == ENOENT)
			{
				string_input(vector[0]);
				string_input(": 0: unable ");
				string_input(vector[1]);
				putchar_error('\n');
				putchar_error(EMPTY_BUFFER);
				exit(99);
			}
			return (EXIT_FAILURE);
		}
		ptrstruct->outputfd = x;
	}
	linked_environ(ptrstruct);
	study_hist(ptrstruct);
	big_loop(ptrstruct, vector);
	return (EXIT_SUCCESS);
}
