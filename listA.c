#include "simpleshell.h"

/**
 * listextent - determines list length
 * @he: node
 * Return: listsize
 */
size_t listextent(const linked_x *he)
{
	size_t m = 0;

	while (he)
	{
		he = he->next;
		m++;
	}
	return (m);
}

/**
 * linkedstring - returns string array
 * @hd: first node
 * Return: array
 */
char **linkedstring(linked_x *hd)
{
	linked_x *our_node = hd;
	size_t i = listextent(hd), k;
	char **strs;
	char *str;

	if (!hd || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; our_node; our_node = our_node->next, i++)
	{
		str = malloc(length_string(our_node->ptrstr) + 1);
		if (!str)
		{
			for (k = 0; k < i; k++)
				free(strs[k]);
			free(strs);
			return (NULL);
		}

		str = stringduplicate(str, our_node->ptrstr);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * outputlinked - prints all elements
 * @hd: first node
 * Return: list size
 */
size_t outputlinked(const linked_x *hd)
{
	size_t v = 0;

	while (hd)
	{
		_puts(change_num(hd->numberA, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(hd->ptrstr ? hd->ptrstr : "(nil)");
		_puts("\n");
		hd = hd->next;
		v++;
	}
	return (v);
}

/**
 * beginnode - returns node
 * @our_node: pointer to list head
 * @before: string to match
 * @ch: the next character
 * Return: match node or null
 */
linked_x *beginnode(linked_x *our_node, char *before, char ch)
{
	char *p = NULL;

	while (our_node)
	{
		p = begin(our_node->ptrstr, before);
		if (p && ((ch == -1) || (*p == ch)))
			return (our_node);
		our_node = our_node->next;
	}
	return (NULL);
}

/**
 * findnode - gets the index
 * @hd: list head
 * @our_node:node
 * Return: index of node or -1
 */
ssize_t findnode(linked_x *hd, linked_x *our_node)
{
	size_t n = 0;

	while (hd)
	{
		if (hd == our_node)
			return (n);
		hd = hd->next;
		n++;
	}
	return (-1);
}
