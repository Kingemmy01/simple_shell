#include "shell.h"

/**
 * parser - tokenizing input argument
 *
 * @buff: user input
 * @argv: argument vector
 * @delimiter: unique characters
 *
 */
void parser(char *buff, char **argv, const char *delimiter)
{
	char  *token;
	int i = 0;

	token = _strtok(buff, delimiter);
	while (token != NULL && i < ARGV_MAX - 1)
	{
		argv[i++] = my_strdup(token);
		token = _strtok(NULL, delimiter);
	}
	argv[i] = NULL;
}
