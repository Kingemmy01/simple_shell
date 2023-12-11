#include "shell.h"

/**
 * c_execute - function to execute commands
 * @path: the path
 * @args: argument vector
 * @env: environment variables
 * @av: argument count
 * Return: 0 on success
 */
int c_execute(char **av, char *path, char **args, char **env)
{
	int r;
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror(av[0]);
		exit(1);
	}
	else if (pid == 0)
	{
		r = execve(path, args, env);
		if (r == -1)
		{
			perror(av[0]);
		}
	}
	else
	{
		int status;

		wait(&status);

	}
	return (0);
}
