#include "shell.h"

/**
 * error_note - printing error message on display
 * @av: program name
 * @argv: argument vector
 * @i: the counter when the prompt enters
 * a command
 */

void error_note(char *av, int i, char *argv)
{
	int leng_1, leng_2, temp = i;
	char num;

	leng_1 = _strlen(av);
	leng_2 = _strlen(argv);
	write(2, av, leng_1);
	fflush(stdin);
	write(2, ": ", 2);
	if (i < 10)
	{
		num = i + '0';
		write(2, &num, 1);
	}
	else if (i > 9 && i < 100)
	{
		num = (i / 10) + '0';
		write(2, &(num), 1);
		num = (temp % 10) + '0';
		write(2, &(num), 1);
	}
	write(2, ": ", 2);
	write(2, argv, leng_2);
	write(2, ": ", 2);
	write(2, "not found\n", 10);
}

/**
 * free_argv - functions that free argument vector
 * @argv: argument vector
 */
void free_argv(char **argv)
{
	int i = 0;

	for (; argv[i] != NULL; i++)
	{
		free(argv[i]);
	}
}

