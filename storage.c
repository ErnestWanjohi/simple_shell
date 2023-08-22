#include "simpleshell.h"

/**
 * escapepointer - freer
 * @ptrA: freed adress pointer
 * Return: 1 success,else 0.
 */
int escapepointer(void **ptrA)
{
	if (ptrA && *ptrA)
	{
		free(*ptrA);
		*ptrA = NULL;
		return (1);
	}

	return (0);
}
