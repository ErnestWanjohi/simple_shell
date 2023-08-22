#include "simpleshell.h"

/**
 * chaincharchecker - checks
 * @ptrstruct: the parameter struct
 * @buffn: buff info
 * @address: adress
 * Return: success
 */
int chaincharchecker(information_x *ptrstruct, char *buffn, size_t *address)
{
	size_t a = *address;

	if (buffn[a] == '|' && buffn[a + 1] == '|')
	{
		buffn[a] = 0;
		a++;
		ptrstruct->buf_identity = COMAND_TWO;
	}
	else if (buffn[a] == '&' && buffn[a + 1] == '&')
	{
		buffn[a] = 0;
		a++;
		ptrstruct->buf_identity = COMAND_BOTH;
	}
	else if (buffn[a] == ';')
	{
		buffn[a] = 0;
		ptrstruct->buf_identity = COMAND_BOND;
	}
	else
		return (0);
	*address = a;
	return (1);
}

/**
 * bond_checker - checks bond
 * @ptrstruct: parametr
 * @buffz: the char buffer
 * @address: address
 * @z: starting point
 * @extent: extent
 * Return: success
 */
void bond_checker(information_x *ptrstruct, char *buffz, size_t *address,
		size_t z, size_t extent)
{
	size_t m = *address;

	if (ptrstruct->buf_identity == COMAND_BOTH)
	{
		if (ptrstruct->state)
		{
			buffz[z] = 0;
			m = extent;
		}
	}
	if (ptrstruct->buf_identity == COMAND_TWO)
	{
		if (!ptrstruct->state)
		{
			buffz[z] = 0;
			m = extent;
		}
	}

	*address = m;
}

/**
 * changefake - changes
 * @ptrstruct: parameter
 * Return: 1 success, else 0
 */
int changefake(information_x *ptrstruct)
{
	int v;
	linked_x *our_node;
	char *p;

	for (v = 0; v < 10; v++)
	{
		our_node = beginnode(ptrstruct->aka, ptrstruct->argvector[0], '=');
		if (!our_node)
			return (0);
		free(ptrstruct->argvector[0]);
		p = find_char(our_node->ptrstr, '=');
		if (!p)
			return (0);
		p = string_duplicator(p + 1);
		if (!p)
			return (0);
		ptrstruct->argvector[0] = p;
	}
	return (1);
}

/**
 * variablechanger - changes vars
 * @ptrstruct: parameter
 * Return: success
 */
int variablechanger(information_x *ptrstruct)
{
	int y = 0;
	linked_x *our_node;

	for (y = 0; ptrstruct->argvector[y]; y++)
	{
		if (ptrstruct->argvector[y][0] != '$' || !ptrstruct->argvector[y][1])
			continue;

		if (!comparison(ptrstruct->argvector[y], "$?"))
		{
			stringchanger(&(ptrstruct->argvector[y]),
					string_duplicator(change_num(ptrstruct->state, 10, 0)));
			continue;
		}
		if (!comparison(ptrstruct->argvector[y], "$$"))
		{
			stringchanger(&(ptrstruct->argvector[y]),
					string_duplicator(change_num(getpid(), 10, 0)));
			continue;
		}
		our_node = beginnode(ptrstruct->environment,
				&ptrstruct->argvector[y][1], '=');
		if (our_node)
		{
			stringchanger(&(ptrstruct->argvector[y]),
					string_duplicator(find_char(our_node->ptrstr, '=') + 1));
			continue;
		}
		stringchanger(&ptrstruct->argvector[y], string_duplicator(""));

	}
	return (0);
}

/**
 * stringchanger - change string with another
 * @oaddress: prev address
 * @naddress: string new
 * Return: successs
 */
int stringchanger(char **oaddress, char *naddress)
{
	free(*oaddress);
	*oaddress = naddress;
	return (1);
}
