#include "shell.h"

/**
 * _getline_helper - functions that help getline
 * @ptr: string to input
 * @buff_size:  input int
 * Return: int
 */
int _getline_helper(char **ptr, size_t *buff_size)
{
	if (*ptr == NULL || *buff_size == 0)
	{
		*buff_size = 128;
		*ptr = malloc(*buff_size);
		if (*ptr == NULL)
			return (-1);
	}
	return (0);
}

/**
 * _getline - reads the input from FILE stream
 * @ptr: string input
 * @buff_size: int input
 * @stream:  input FILE
 * Return: ssize_t
 */
ssize_t _getline(char **ptr, size_t *buff_size, FILE *stream)
{
	ssize_t bytes = 0;
	size_t position = 0, newSize;
	static char buf[READ_BUF_SIZE];
	static size_t bufSize, bufPos;
	char *newBuffer;

	if (ptr == NULL || buff_size == NULL || stream == NULL
		|| _getline_helper(ptr, buff_size) == -1)
		return (-1);
	while (1)
	{
		if (bufPos >= bufSize)
		{
			bytes = read(stream->_fileno, buf, READ_BUF_SIZE);
			if (bytes <= 0 && position == 0)
				return (-1);
			else if (bytes <= 0)
				break;
			bufSize = bytes;
			bufPos = 0;
		}
		if (position >= *buff_size - 1)
		{
			newSize = *buff_size * 2;
			newBuffer = realloc(*ptr, newSize);
			if (newBuffer == NULL)
				return (-1);
			*ptr = newBuffer;
			*buff_size = newSize;
		}
		(*ptr)[position++] = buf[bufPos++];
		if ((*ptr)[position - 1] == '\n')
			break;
	}
	(*ptr)[position] = '\0';
	return (position);
}

/**
 **_memset - fills memory with a constant byte
 *@p: the pointer pointing to the memory area
 *@b: the byte to fill *p
 *@n: the amount of bytes to be filled
 *Return:  a pointer to the memory area p
 */
char *_memset(char *p, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		p[i] = b;
	return (p);
}

/**
 * ffree - function that frees a string of strings
 * @ss: string of strings
 */
void ffree(char **ss)
{
	char **a = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(a);
}

/**
 * _realloc - function that reallocates a block of memory
 * @ptr: A pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to the old block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *c;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	c = malloc(new_size);
	if (!c)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		c[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (c);
}

