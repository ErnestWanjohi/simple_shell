#include "simpleshell.h"


/**
 * start_information - start the linked_x list
 * @ptrstruct: ptr to our struct
 */
void start_information(information_x *ptrstruct)
{
	ptrstruct->way = NULL;
	ptrstruct->argvector = NULL;
	ptrstruct->argument = NULL;
	ptrstruct->argcount = 0;

}
/**
 * begin_struct - begins our information structure
 * @ptrstruct: ptr to our structure
 * @avector: arg vector
 */
void begin_struct(information_x *ptrstruct, char **avector)
{
	int x = 0;

	ptrstruct->fileidentity = avector[0];
	if (ptrstruct->argument)
	{
		ptrstruct->argvector = stringsplitter(ptrstruct->argument, "\t");
	}
	if (!ptrstruct->argvector)
	{
		ptrstruct->argvector = malloc(sizeof(char *) * 2);
		if (ptrstruct->argvector)
		{
			ptrstruct->argvector[0] = strdup(ptrstruct->argument);
			ptrstruct->argvector[1] = NULL;
		}
	}
	x = 0;
	while (ptrstruct->argvector && ptrstruct->argvector[x])
	{
		ptrstruct->argcount = x;

		changefake(ptrstruct);
		variablechanger(ptrstruct);
		x++;
	}
}
/**
 * release_info - free infoo
 * @ptrstruct: ptr to our struct
 * @whole: means all
 */
void release_info(information_x *ptrstruct, int whole)
{
	escape(ptrstruct->argvector);
	ptrstruct->argvector = NULL;
	ptrstruct->way = NULL;

	if (whole)
	{
		if (ptrstruct->environment)
		{
			escapelist(&(ptrstruct->environment));
		}
		if (!ptrstruct->prompt_buffer)
		{
			free(ptrstruct->argument);
		}
		if (ptrstruct->thepast)
		{
			escapelist(&(ptrstruct->thepast));
		}
		if (ptrstruct->aka)
		{
			escapelist(&(ptrstruct->aka));
		}
		escape(ptrstruct->env1);
		ptrstruct->env1 = NULL;
		escapepointer((void **)ptrstruct->prompt_buffer);
		if (ptrstruct->outputfd > 2)
		{
			close(ptrstruct->outputfd);
			_putchar(EMPTY_BUFFER);
		}
	}
}
