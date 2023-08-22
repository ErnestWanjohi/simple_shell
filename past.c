#include "simpleshell.h"
/**
 * linked_hist - add input to a linked list
 * @ptrstruct: ptr to struct
 * @bufferA: buffer
 * @counter: counter
 * Return (0);
 */
int linked_hist(information_x *ptrstruct, char *bufferA, int counter)
{
	linked_x *our_node = NULL;

	if (ptrstruct->thepast)
	{
		our_node = ptrstruct->thepast;
		finalisenode(&our_node, bufferA, counter);
	}
	else
	{
		ptrstruct->thepast = our_node;
	}
	return (0);
}
/**
 * output_hist - outputs hists
 * @ptrstruct: ptr hist
 * Return: 1
 */
int output_hist(information_x *ptrstruct)
{
	linked_x *our_node = NULL;
	char *our_file = wayback_file(ptrstruct);
	ssize_t q;

	if (!our_file)
	{
		return (1);
	}
	q = open(our_file, O_TRUNC | O_CREAT | O_RDWR | 0644);
	our_node = ptrstruct->thepast;
	while (our_node)
	{
		write_str_fd(our_node->ptrstr, q);
		write_fd('\n', q);
		our_node = our_node->next;
	}
	write_fd(EMPTY_BUFFER, q);
	return (1);
}
/**
 * new_num - gives the registered lists a new num
 * @ptrstruct: ptr to structure
 * Return: 0
 */
int new_num(information_x *ptrstruct)
{
	int x = 0;
	linked_x *our_node = ptrstruct->thepast;

	while (our_node)
	{
		our_node->numberA = x++;
		our_node = our_node->next;
	}
	return (ptrstruct->lengthhist = x);
}
/**
 * wayback_file - finds the hist  ory filess
 * @ptrstruct: ptr to our struct
 * Return: buffer
 */
char *wayback_file(information_x *ptrstruct)
{
	char *add;
	char *bufferA;

	add =  value_env(ptrstruct, "HOME=");
	if (!add)
	{
		return (NULL);
	}
	bufferA = malloc(sizeof(char) * (length_string(add)
			+ length_string(OLD_F) + 2));
	if (bufferA == NULL)
	{
		return (NULL);
	}
	bufferA[0] == 0;
	strcpy(bufferA, add);
	concatenation(bufferA, "/");
	concatenation(bufferA, OLD_F);
	return (bufferA);
}
/**
 * study_hist - reading hist
 * @ptrstruct: ptr struct
 * Return: 0
 */
int study_hist(information_x *ptrstruct)
{
	char *bufferA = NULL;
	char *our_file = wayback_file(ptrstruct);
	int end = 0, counter = 0, x;
	struct stat wq;
	ssize_t q, fd, lenf = 0;

	if (!our_file)
	{
		return (0);
	}
	fd = open(our_file, O_RDONLY);
	free(our_file);
	if (fd == -1)
	{
		return (0);
	}
	if (!fstat(fd, &wq))
	{
		lenf = wq.st_size;
	}
	if (lenf < 2)
	{
		return (0);
	}
	bufferA = malloc(sizeof(char) * (lenf + 1));
	if (!bufferA)
	{
		return (0);
	}
	q = read(fd, bufferA, lenf);
	bufferA[lenf] = 0;
	if (q <= 0)
	{
		return (free(bufferA), 0);
	}
	close(fd);
	x = 0;
	while (x < lenf)
	{
		if (bufferA[x] == '\n')
		{
			bufferA[x] = 0;
			linked_hist(ptrstruct, bufferA + end, counter++);
			end = x + 1;
		}
		x++;
	}
	if (end != x)
	{
		linked_hist(ptrstruct, bufferA + end, counter++);
	}
	free(bufferA);
	ptrstruct->lengthhist = counter;
	while (ptrstruct->lengthhist-- >= FINAL_HIST)
	{
		eliminatenode(&(ptrstruct->thepast), 0);
	}
	new_num(ptrstruct);
	return (ptrstruct->lengthhist);
}
