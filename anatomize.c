#include "simpleshell.h"
/**
 * execcmd - excutability
 * @ptrstruct: ptr to struct
 * @way: pathway
 * Return: 1 if true,else 0
 */
int execcmd(information_x *ptrstruct, char *way)
{
	struct stat st;

	(void)ptrstruct;
	if (!way || stat(way, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * copychars - characters copier
 * @waystring: way of string
 * @begin:  begin
 * @end: index ebd
 * Return: buffer
 */
char *copychars(char *waystring, int begin, int end)
{
	static char buf[1024];
	int m = 0, k = 0;

	for (m = 0, m = begin; m < end; m++)
		if (waystring[m] != ':')
			buf[k++] = waystring[m];
	buf[k] = 0;
	return (buf);
}

/**
 * locateway - locates cmd
 * @ptrstruct: pointer to struct
 * @waystr: the str way
 * @comand: the comand locate
 * Return: comand path
 */
char *locateway(information_x *ptrstruct, char *waystr, char *comand)
{
	int w = 0, now = 0;
	char *way;

	if (!waystr)
		return (NULL);
	if ((length_string(comand) > 2) && begin(comand, "./"))
	{
		if (execcmd(ptrstruct, comand))
			return (comand);
	}
	while (1)
	{
		if (!waystr[w] || waystr[w] == ':')
		{
			way = copychars(waystr, now, w);
			if (!*way)
				concatenation(way, comand);
			else
			{
				concatenation(way, "/");
				concatenation(way, comand);
			}
			if (execcmd(ptrstruct, way))
				return (way);
			if (!waystr[w])
				break;
			now  = w;
		}
		w++;
	}
	return (NULL);
}
