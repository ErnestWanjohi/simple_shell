#include "simpleshell.h"

/**
 * fillmemory - memory filler
 * @sm: mem pointer
 * @bsm: sm filler
 * @q: byte amount
 * Return: success
 */
char *fillmemory(char *sm, char bsm, unsigned int q)
{
	unsigned int k;

	for (k = 0; k < q; k++)
		sm[k] = bsm;
	return (sm);
}

/**
 * escape - string escape
 * @pstr: pointer
 */
void escape(char **pstr)
{
	char **u = pstr;

	if (!pstr)
		return;
	while (*pstr)
		free(*pstr++);
	free(u);
}

/**
 * memorychanger - changes memory
 * @omb: old malloc block memore
 * @os: old block memory
 * @ns: new  size block
 * Return: success
 */
void *memorychanger(void *omb, unsigned int os, unsigned int ns)
{
	char *k;

	if (!omb)
		return (malloc(ns));
	if (!ns)
		return (free(omb), NULL);
	if (ns == os)
		return (omb);

	k = malloc(ns);
	if (!k)
		return (NULL);

	os = os < ns ? os : ns;
	while (os)
		k[os] = ((char *)omb)[os];
	free(omb);
	return (k);
}
