#include "simpleshell.h"
/**
 * big_loop - loop
 * @ptrstruct: info prameter
 * @vector: vector
 * Return: 0 on success else 1
 */
int big_loop(information_x *ptrstruct, char **vector)
{
	ssize_t q = 0;
	int madeup = 0;

	while (q != -1 && madeup != -2)
	{
		start_information(ptrstruct);
		if (joining(ptrstruct))
			_puts("$ ");
		_putchar(EMPTY_BUFFER);
		q = read_process(ptrstruct);
		if (q != -1)
		{
			begin_struct(ptrstruct, vector);
			madeup = locatemadeup(ptrstruct);
			if (madeup == -1)
				locatecomand(ptrstruct);
		}
		else if (joining(ptrstruct))
			_putchar('\n');
		release_info(ptrstruct, 0);
	}
	output_hist(ptrstruct);
	release_info(ptrstruct, 1);
	if (!joining(ptrstruct) && ptrstruct->state)
		exit(ptrstruct->state);
	if (madeup == -2)
	{
		if (ptrstruct->wrong_number == -1)
			exit(ptrstruct->state);
		exit(ptrstruct->wrong_number);
	}
	return (madeup);
}

/**
 * locatemadeup- locates command
 * @ptrstruct: parameter struct
 * Return: -1 builtin not found,
 * 0 successfully,
 * 1successful,
 * else 2
 */
int locatemadeup(information_x *ptrstruct)
{
	int q, madeup = -1;
	madeup_x madeint[] = {
		{"gw", gate_way},
		{"now", now_environment},
		{"ncd", now_cd},
		{"past", way_back},
		{"neww", new_environment},
		{"deleteenv", delete_environment},
		{"cd", change_directory},
		{"aka", fake_alias},
		{NULL, NULL}
	};

	for (q = 0; madeint[q].variety; q++)
		if (comparison(ptrstruct->argvector[0], madeint[q].variety) == 0)
		{
			ptrstruct->band_length++;
			madeup = madeint[q].fptr(ptrstruct);
			break;
		}
	return (madeup);
}

/**
 * locatecomand - locates command.
 * @ptrstruct: struct
 * Return: success
 */
void locatecomand(information_x *ptrstruct)
{
	char *plan = NULL;
	int m, k;

	ptrstruct->way = ptrstruct->argvector[0];
	if (ptrstruct->flaglength == 1)
	{
		ptrstruct->band_length++;
		ptrstruct->flaglength = 0;
	}
	for (m = 0, k = 0; ptrstruct->argument[m]; m++)
		if (!separator(ptrstruct->argument[m], " \t\n"))
			k++;
	if (!k)
		return;

	plan = locateway(ptrstruct, value_env(ptrstruct, "PATH="),
			ptrstruct->argvector[0]);
	if (plan)
	{
		ptrstruct->way = plan;
		newcomand(ptrstruct);
	}
	else
	{
		if ((joining(ptrstruct) || value_env(ptrstruct, "PATH=")
				|| ptrstruct->argvector[0][0] == '/') && execcmd(ptrstruct,
			ptrstruct->argvector[0]))
		{
			locatecomand(ptrstruct);
		}

		else if (*(ptrstruct->argument) != '\n')
		{
			ptrstruct->state = 127;
		output_error(ptrstruct, "not located\n");
		}
	}
}

/**
 * newcomand -cmd fork
 * @ptrstruct: parameter struct
 * Return: void
 */
void newcomand(information_x *ptrstruct)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{

		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(ptrstruct->way, ptrstruct->argvector,
					discover_env(ptrstruct)) == -1)
		{
			release_info(ptrstruct, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}

	}
	else
	{
		wait(&(ptrstruct->state));
		if (WIFEXITED(ptrstruct->state))
		{
			ptrstruct->state = WEXITSTATUS(ptrstruct->state);
			if (ptrstruct->state == 126)
				output_error(ptrstruct, "Access failed\n");
		}
	}
}
