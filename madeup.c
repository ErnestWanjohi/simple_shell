#include "simpleshell.h"
/**
 * change_directory - changes diR
 * @ptrstruct: ptr
 * Return: 0
 */
int change_directory(information_x *ptrstruct)
{
	int value;
	char *page, buffer[1024], *x;

	x = getcwd(buffer, 1024);
	if (!x)
	{
		_puts("invalid\n");
	}
	if (!ptrstruct->argvector[1])
	{
		page = value_env(ptrstruct, "HOME=");
		if (!page)
		{
			chdir((page = value_env(ptrstruct, "PWD=") ? page : "/"));
		}
		else
		{
			value = chdir(page);
		}
	}
	else if (strcmp(ptrstruct->argvector[1], "-") == 0)
	{
		if (!value_env(ptrstruct, "OLDPWD="))
		{
			_puts(x);
			_putchar('\n');
			return (1);
		}
	_puts(value_env(ptrstruct, "OLDPWD="));
		_putchar('\n');
	}
	else
	{
		value = chdir(ptrstruct->argvector[1]);
		if (value == -1)
		{
			output_error(ptrstruct, "unable to cd");
			string_input(ptrstruct->argvector[1]), putchar_error('\n');
		}
		else
		{
			setenv_(ptrstruct, "OLDPWD", value_env(ptrstruct, "PWD="));
			setenv_(ptrstruct, "PWD", getcwd(buffer, 1024));
		}
	}
		return (0);
}
/**
 * gate_way - it exits the bash
 * @ptrstruct: pointer to structure
 * Return: -1
 */
int gate_way(information_x *ptrstruct)
{
	int lookend;

	if (ptrstruct->argvector[1])
	{
		lookend = str_to_int(ptrstruct->argvector[1]);
		if (lookend == -1)
		{
			ptrstruct->state = 2;
			output_error(ptrstruct, "prohibited");
			string_input(ptrstruct->argvector[1]);
			putchar_error('\n');
			return (1);
		}
		ptrstruct->wrong_number = str_to_int(ptrstruct->argvector[1]);
		return (-2);
	}
	ptrstruct->wrong_number = -1;
	return (-2);
}
/**
 * now_cd - vhange in cd in the procexx
 * @ptrstruct: pointer to struct
 * Return: (0)
 */
int now_cd(information_x *ptrstruct)
{
	char **arr;

	arr = ptrstruct->argvector;

	_puts("no func\n");
	if (0)
	{
		_puts(*arr);
	}
	return (0);
}
