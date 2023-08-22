#include "simpleshell.h"


/**
 * unsetenv - func to remove an enviromntal variable
 * @ptrstruct: pointer to our structure
 * @rem_var: ptr t str to be removed
 * Return: 0 success
 */
int unsetenv_(information_x *ptrstruct, char *rem_var)
{
	linked_x *our_node = ptrstruct->environment; /*this points to begin of list*/
	size_t x = 0; /*counter of keep track of index*/
	char *q;

	if (!our_node || !rem_var)
	{
		return (0);
	}
	while (our_node) /*iterate through list*/
	{
		q = begin(our_node->ptrstr, rem_var); /*check if node is our var*/
		if (q && *q == '=') /*format checker*/
		{
			ptrstruct->swapenv = eliminatenode(&(ptrstruct->environment), x);
			x = 0;
			our_node = ptrstruct->environment; /*set to beggining of list*/
			continue;
		}
		our_node = our_node->next;
		x++;
	}
	return (ptrstruct->swapenv);
}
/**
 * setenv - adds new variable or configures a newi one
 * @ptrstruct: ptr to our structure
 * @add_variable: pointer to string we wanna add to our environ list
 * @equal: the value = in this case
 * Return: 0 success
 */
int setenv_(information_x *ptrstruct, char *add_variable, char *equal)
{
	linked_x *our_node;
	char *BUFFER = NULL;
	char *q;

	if (!add_variable || !equal)
	{
		return (0);
	}
	BUFFER = malloc(length_string(add_variable) + length_string(equal) + 2);
	if (BUFFER == NULL)
	{
		return (0);
	}
	strcpy(BUFFER, add_variable);
	concatenation(BUFFER, "=");
	concatenation(BUFFER, equal);
	our_node = ptrstruct->environment;
	while (our_node)
	{
		q = begin(our_node->ptrstr, add_variable);
		if (q && *q == '=')
		{
			free(our_node->ptrstr);
			our_node->ptrstr = BUFFER;
			ptrstruct->swapenv = 1;
			return (0);
		}
		our_node = our_node->next;
	}
	finalisenode(&(ptrstruct->environment), BUFFER, 0);
	free(BUFFER);
	ptrstruct->swapenv = 1;
	return (0);
}
/**
 * discover_env - find  str of our environ
 * @ptrstruct: pointer to struct:
 * Return: our string of environ
 */
char **discover_env(information_x *ptrstruct)
{
	if (!ptrstruct->env1 || ptrstruct->swapenv)
	{
		ptrstruct->env1 = linkedstring(ptrstruct->environment);
		ptrstruct->swapenv = 0;
	}
	return (ptrstruct->env1);
}
