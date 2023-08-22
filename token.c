#include "simpleshell.h"

/**
 * **stringsplitter - sp
 * @string: input
 * @dlm: string dml
 * Return: success to arary of strings ele
 * null
 */

char **stringsplitter(char *string, char *dlm)
{
	int n, t, x, m, numberrds = 0;
	char **mas;

	if (string == NULL || string[0] == 0)
		return (NULL);
	if (!dlm)
		dlm = " ";
	for (n = 0; string[n] != '\0'; n++)
		if (!separator(string[n], dlm) && (separator(string[n + 1], dlm)
					|| !string[n + 1]))
			numberrds++;

	if (numberrds == 0)
		return (NULL);
	mas = malloc((1 + numberrds) * sizeof(char *));
	if (!mas)
		return (NULL);
	for (n = 0, t = 0; t < numberrds; t++)
	{
		while (separator(string[n], dlm))
			n++;
		x = 0;
		while (!separator(string[n + x], dlm) && string[n + x])
			x++;
		mas[t] = malloc((x + 1) * sizeof(char));
		if (!mas[t])
		{
			for (x = 0; x < t; x++)
				free(mas[x]);
			free(mas);
			return (NULL);
		}
		for (m = 0; m < x; m++)
			mas[t][m] = string[n++];
		mas[t][m] = 0;
	}
	mas[t] = NULL;
	return (mas);
}

/**
 * **stringtoword - splits to word
 * @string: input string
 * @w: xxxx
 * Return: success
 */
char **stringtoword(char *string, char w)
{
	int l, z, k, n, numberrds = 0;
	char **sup;

	if (string == NULL || string[0] == 0)
		return (NULL);
	for (l = 0; string[l] != '\0'; l++)
		if ((string[l] != w && string[l + 1] == w) ||
				    (string[l] != w && !string[l + 1]) || string[l + 1] == w)
			numberrds++;
	if (numberrds == 0)
		return (NULL);
	sup = malloc((1 + numberrds) * sizeof(char *));
	if (!sup)
		return (NULL);
	for (l = 0, z = 0; z < numberrds; z++)
	{
		while (string[l] == w && string[l] != w)
			l++;
		k = 0;
		while (string[l + k] != w && string[l + k] && string[l + k] != w)
			k++;
		sup[z] = malloc((k + 1) * sizeof(char));
		if (!sup[z])
		{
			k = 0;

			while (k < z)
			{
				free(sup[k]);
				k++;
			}
			free(sup);
			return (NULL);
		}
		for (n = 0; n < k; n++)
			sup[z][n] = string[l++];
		sup[z][n] = 0;
	}
	sup[z] = NULL;
	return (sup);
}
