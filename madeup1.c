#include "simpleshell.h"
/**
 * alias_output - writes an output alias
 * @our_node: our node
 * Return: 0
 */
int alias_output(linked_x *our_node)
{
	char *x = NULL;
	char *q = NULL;

	if (our_node)
	{
		q = find_char(our_node->ptrstr, '=');
		x = our_node->ptrstr;
		while (x <= q)
		{
			_putchar(*x);
			_putchar('/');
			_puts(q + 1);
			_puts("\n");
			x++;
		}
	}
		return (0);
}

/**
 * way_back - shows the hisry starting wit a nunber
 * @ptrstruct: pointer to strucure
 * Return: 0
 */
int way_back(information_x *ptrstruct)
{
	outputlinked(ptrstruct->thepast);
	return (0);
}
/**
 * fake_alias - copies the real alias
 * @ptrstruct: pointer to struct
 * Return: 0
 */
int fake_alias(information_x *ptrstruct)
{
	char *w = NULL;
	int x = 0;
	linked_x *our_node = NULL;

	if (ptrstruct->argcount == 1)
	{
		our_node = ptrstruct->aka;

		while (our_node)
		{
			alias_output(our_node);
			our_node = our_node->next;
		}
		return (0);
	}
	x = 1;
	while (ptrstruct->argvector[x])
	{
		w = find_char(ptrstruct->argvector[x], '=');

		if (w)
		{
			give_alias(ptrstruct, ptrstruct->argvector[x]);
		}
		else
		{
		alias_output(beginnode(ptrstruct->aka, ptrstruct->argvector[x], '='));
		}
		x++;
	}
	return (0);
}
/**
 * give_alias - outputs str alias
 * @ptrstruct: pointer to struct
 * @string: str
 * Return: 1
 */
int give_alias(information_x *ptrstruct, char *string)
{
	char *x;

	x = find_char(string, '=');

	if (!x)
	{
		return (1);
	}
	if (!*++x)
	{
		return (remove_alias(ptrstruct, string));
	}
	remove_alias(ptrstruct, string);
	return (finalisenode(&(ptrstruct->aka), string, 0) == NULL);
}
/**
 * remove_alias - its takes out aan alias
 * @ptrstruct: pointer to our struct
 * @str: the string
 * Return: 1
 */
int remove_alias(information_x *ptrstruct, char *str)
{
	char ch;
	char *k;
	int value;

	k = find_char(str, '=');

	if (!k)
	{
		return (1);
	}
	ch = *k;
	*k = 0;

	value = eliminatenode(&(ptrstruct->aka),
			findnode(ptrstruct->aka, beginnode(ptrstruct->aka,
			str, -1)));
	*k = ch;

	return (value);
}
