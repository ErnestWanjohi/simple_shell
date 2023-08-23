#include "simpleshell.h"




/**
 * new_environment - new
 * @ptrstruct: pointer
 * Return: 0
 */
int new_environment(information_x *ptrstruct)
{
	if (ptrstruct->argcount != 3)
	{
		string_input("errorr arguments\n");
		return (1);
	}
	if (setenv_(ptrstruct, ptrstruct->argvector[1], ptrstruct->argvector[2]))
	{
		return (0);
	}
	return (1);
}
/**
 * value_env - environ variable val
 * @ptrstruct: pointer
 * @identity: namee
 * Return: NULL
 */
char *value_env(information_x *ptrstruct, char *identity)
{
	char *ptrr;

	linked_x *our_node = ptrstruct->environment;

	while (our_node)
	{
		ptrr = begin(our_node->ptrstr, identity);

		if (ptrr && *ptrr)
		{
			return (ptrr);
		}
		our_node = our_node->next;
	}
	return ('\0');
}
/**
 * now_environment - outputs
 * @ptrstruct: pointer to our strucutre
 * Return: 0
 */
int now_environment(information_x *ptrstruct)
{
	outputlinkedstr(ptrstruct->environment);
	return (0);
}
/**
 * delete_environment - reoves enviromentts
 * @ptrstruct:pointer to truct
 * Return: 0
 */
int delete_environment(information_x *ptrstruct)
{
	int z;

	if (ptrstruct->argcount == 1)
	{
		string_input("need more argumnts\n");
		return (1);
	}
	z = 1;
	while (z <= ptrstruct->argcount)
	{
		unsetenv_(ptrstruct, ptrstruct->argvector[z]);
	}
	return (0);
}
/**
 * linked_environ - environment lists
 * @ptrstruct: pointer to our strucute
 * Return: 0
 */
int linked_environ(information_x *ptrstruct)
{
	size_t x;
	linked_x *our_node = NULL;

	 x = 0;
	while (environ[x])
	{
		finalisenode(&our_node, environ[x], 0);
		x++;
	}
	ptrstruct->environment = our_node;

	return (0);
}
