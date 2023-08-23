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
	size_t b;
	static char bufA[STUDY_BUFFER_LEN];
	static size_t z, width;
	ssize_t x = 0, t = 0;
	char *ptrr = NULL, *nowz = NULL, *vv;

	ptrr = *input_ptr;
	if (ptrr && length)
		t = *length;
	if (z == width)
		z = width = 0;
	/*whats the buffer*/
	x = takes_the_buffer(ptrstruct, bufA, &width);
	if (x == -1 || (x == 0 && width == 0))
		return (-1);
	/*takes the buffer*/
	vv = find_char(bufA + z, '\n');
	b = vv ? 1 + (unsigned int)(vv - bufA) : width;
	nowz = memorychanger(ptrr, t, t ? t + b : b + 1);
	if (!nowz)
		return (ptrr ? free(ptrr), -1 : -1);

	if (t)
		strncat_(nowz, bufA + z, b - z);
	else
		stringncopy_(nowz, bufA + z, b - z + 1);

	t += b - z;
	z = b;
	ptrr = nowz;

	if (length)
		*length = t;
	*input_ptr = ptrr;
	return (t);
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
		free(*bufer);
		*bufer = NULL;
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
