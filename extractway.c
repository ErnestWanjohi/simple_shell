#include "simpleshell.h"

/**
 * takes_the_buffer - reads a given buffer
 * @ptrstruct: ptr to our strucure
 * @buf: the defined buffer
 * @s: size
 * Return: READ BYTES
 */
ssize_t takes_the_buffer(information_x  *ptrstruct, char *buf, size_t *s)
{
	ssize_t k = 0;

	if (*s)
	{
		return (0);
	}
	k = read(ptrstruct->outputfd, buf, STUDY_BUFFER_LEN);
	if (k >= 0)
	{
		*s = k;
	}
	return (k);
}
/**
 * custom_getline - custom get line func
 * @ptrstruct: pointer to our structure
 * @input_ptr: pointer to buff
 * @length: size
 * Return: bytes read
 */
int custom_getline(information_x *ptrstruct, char **input_ptr, size_t *length)
{
	ssize_t x = 0, q = 0, w;
	char *pointer = NULL;
	char *buffer_new = NULL, *v;
	static char BUFFER[STUDY_BUFFER_LEN];
	static size_t m, lennn;

	pointer = *input_ptr;
	if (pointer && length)
	{
		q = *length;
	}
	if (m == lennn)
	{
		m = lennn = 0;
	}
	x = takes_the_buffer(ptrstruct, BUFFER, &lennn);
	if (x == -1 ||(x == 0 && lennn == 0))
	{
		return (-1);
	}
	v = find_char(BUFFER + m, '\n'); /*whare is the new line*/
	w = v ? 1 + (unsigned int)(v - BUFFER) : lennn;
	buffer_new = memorychanger(pointer, q, q ? q + w : w + 1);
	if (!buffer_new)
	{
		return (pointer ? free(pointer), -1 : -1);
	}
	if (q)
		strncat_(buffer_new, BUFFER + 1, w - m);
	else
		stringcopy_(buffer_new, BUFFER + 1, w - m + 1);
	q += w - m;
	m = w;
	pointer = buffer_new;
	if (length)
	{
		*length = q;
		*input_ptr = pointer;
	}
		return (q);
}
/**
 * chain_buffers - handles chained buffers
 * @ptrstruct: - pointer to our struct
 * @bufer: pur buffer
 * @n:length
 * Return: size read
 */
ssize_t chain_buffers(information_x  *ptrstruct, char **bufer, size_t *n)
{
	size_t lenxx = 0;
	ssize_t x = 0;

	if (!*n)
	{
		free(bufer);
		bufer = NULL;
		signal(SIGINT, signal_int);

		#if CUSTOM_LINE
			x = get_line(bufer, &lenxx, stdin);
		#else
			x = custom_getline(ptrstruct, bufer, &lenxx);
		#endif

		if (x > 0)
		{
			if ((*bufer)[x - 1] == '\n')
			{
				(*bufer)[x - 1] = '\n';
				x--;
			}
		}
		ptrstruct->flaglength = 1;
		eliminate_comments(*bufer);
		linked_hist(ptrstruct, *bufer, ptrstruct->lengthhist);
		if (find_char(*bufer, ';'))
		{
			*n = x;
			ptrstruct->prompt_buffer = bufer;
		}
	}
	return (x);
}
/**
 * signal_int - supposed to handle ctrl + c
 * @signalnumber: the sig number
 */
void signal_int(__attribute__((unused))int signalnumber)
{
	_putchar('\n');
	_putchar('$');
	_putchar(' ');
	_putchar(EMPTY_BUFFER);
}
/**
 * read_process - reading input and handle chain cmds
 * @ptrstruct: - pointer to our struct
 * Return: bytes read
 */
ssize_t read_process(information_x *ptrstruct)
{
	ssize_t d = 0;
	static size_t x, lennx;
	static size_t y;
	static char *bufferA; /*chained buffer*/
	char **ptrbuf = &(ptrstruct->argument);
	char *q;

	_putchar(EMPTY_BUFFER);
	d = chain_buffers(ptrstruct, &bufferA, &lennx);  /*read input manage buf*/
	if (d == -1)
	{
		return (-1);  /*eof*/
	}
	if (lennx)
	{
		y = x;
		q = bufferA + x;
		bond_checker(ptrstruct, bufferA, &y, x, lennx);
		while (y < lennx)
		{
			if (chaincharchecker(ptrstruct, bufferA, &y))
			{
				break;
				y++;
			}
		}
	x = y + 1; /*move to next command*/
	if (x >= lennx)
	{
		x = lennx = 0;
		ptrstruct->buf_identity = TRUE_CHAIN;
		*ptrbuf = q;
		return (length_string(q));
	}
	}
	*ptrbuf = bufferA;
	return (d);
}
