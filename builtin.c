#include "shell.h"

/**
 * _builtin - handles builtin commands
 * @buff: user input command
 * @args: argument vector
 * Return: 0 on success
 */
int _builtin(char *buff, char *args[])
{
	if (_strcmp(args[0], "exit") == 0)
	{
	errno = 0;    /*Reset the error code */
		/*free(buff);*/
		free(args);
		exit(0);
	}

	else if (_strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL)
		{
			chdir(getenv("HOME"));
		}
		else
		{
			chdir(args[1]);
		}
			free(buff);
			return (1);
	}
		else if (_strcmp(args[0], "env") == 0)
		{
		_env(); /*call the _env() function */
			return (1);
		}
		else if (_strcmp(args[0], "setenv") == 0 && args[1] && args[2])
		{
		if (setenv(args[1], args[2], 1))
		write(STDERR_FILENO, "setenv: Error setting environment variable\n", 43);
			return (1);
		}
		else if (_strcmp(args[0], "unsetenv") == 0 && args[1])
		{
			if (unsetenv(args[1]))
			write(STDERR_FILENO, "unsetenv: Error unsetting env variable\n", 49);
			return (1);
		}
	return (0);
}
