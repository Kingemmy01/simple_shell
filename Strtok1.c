#include "shell.h"

/**
 * _strtok - customized functions tokenize a string
 * @str: the input string
 * @delimiter: the smallest unit
 *
 * Return: the separated string
 */
char *_strtok(char *str, const char *delimiter)
{
	static char *last;
	char *tok;

	if (str != NULL)
		last = str;

	if (last == NULL)
		return (NULL);

	while (*last != '\0' && _strchr(delimiter, *last) != NULL)
	{
		last++;
	}
	if (*last == '\0')
	{
		return (NULL);
	}
	tok = last;
	while (*last != '\0' && _strchr(delimiter, *last) == NULL)
	{
		last++;
	}
	if (*last != '\0')
	{
		*last++ = '\0';
	}
	else
	{
		last = NULL;
	}
	return (tok);
}
