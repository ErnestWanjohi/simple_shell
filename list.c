#include "simpleshell.h"

/**
 * addupnode - adds node to beginning of the list
 * @hd: address of pointer to head node
 * @strn: field of node
 * @numA: node index history
 * Return: list of size
 */
linked_x *addupnode(linked_x **hd, const char *strn, int numA)
{
	linked_x *newhd;

	if (!hd)
		return (NULL);
	newhd = malloc(sizeof(linked_x));
	if (!newhd)
		return (NULL);
	fillmemory((void *)newhd, 0, sizeof(linked_x));
	newhd->numberA = numA;
	if (strn)
	{
		newhd->ptrstr = string_duplicator(strn);
		if (!newhd->ptrstr)
		{
			free(newhd);
			return (NULL);
		}
	}
	newhd->next = *hd;
	*hd = newhd;
	return (newhd);
}

/**
 * finalisenode - adds node
 * @hd: address of pointer
 * @string: str field
 * @numB: node index
 * Return: size of list
 */
linked_x *finalisenode(linked_x **hd, const char *string, int numB)
{
	linked_x *my_node;
	linked_x *our_node;

	if (!hd)
		return (NULL);

	our_node = *hd;
	my_node = malloc(sizeof(linked_x));
	if (!my_node)
		return (NULL);
	fillmemory((void *)my_node, 0, sizeof(linked_x));
	my_node->numberA = numB;
	if (string)
	{
		my_node->ptrstr = string_duplicator(string);
		if (!my_node->ptrstr)
		{
			free(my_node);
			return (NULL);
		}
	}
	if (our_node)
	{
	for (; our_node->next; our_node = our_node->next)
		our_node->next = my_node;
	}
	else
		*hd = my_node;
	return (my_node);
}

/**
 * outputlinkedstr - outputs only str element
 * @k: first node
 * Return: list size
 */
size_t outputlinkedstr(const linked_x *k)
{
	size_t n = 0;

	while (k)
	{
		_puts(k->ptrstr ? k->ptrstr : "(nil)");
		_puts("\n");
		k = k->next;
		n++;
	}
	return (n);
}

/**
 * eliminatenode - deletes node
 * @hd: pointer to first node
 * @index1: index of node
 * Return: 1 on success, else 0
 */
int eliminatenode(linked_x **hd, unsigned int index1)
{
	linked_x *our_node, *nodebefore;
	unsigned int k = 0;

	if (!hd || !*hd)
		return (0);

	if (!index1)
	{
		our_node = *hd;
		*hd = (*hd)->next;
		free(our_node->ptrstr);
		free(our_node);
		return (1);
	}
	our_node = *hd;
	for (int k = 0; our_node;
			k++, nodebefore = our_node, our_node = our_node->next)
	{
		if (k == index1)
		{
			nodebefore->next = our_node->next;
			free(our_node->ptrstr);
			free(our_node);
			return (1);
		}
	}
	return (0);
}
/**
 * escapelist - frees all nodes in a list
 * @hdptr: address of pointer
 * Return: success
 */
void escapelist(linked_x **hdptr)
{
	linked_x *our_node, *nodeafter, *hd;

	if (!hdptr || !*hdptr)
		return;
	hd = *hdptr;
	our_node = hd;
	while (our_node)
	{
		nodeafter = our_node->next;
		free(our_node->ptrstr);
		free(our_node);
		our_node = nodeafter;
	}
	*hdptr = NULL;
}
