#include "shell.h"
/**
 * main - loop function every time to display prompt
 * @env: acess environment variable
 * @av: program name
 * @c: count
 * Return: 0 on success
 */
int  main(int c, char **av, char **env)
{
	char *buff = NULL;
	char *argv[ARGV_MAX], *path;
	const char *delimiter = " \t\n\r";
	size_t buff_size = 0;
	ssize_t len;
	int mode = isatty(0);

	(void)c;

	while (1)
	{
		if (mode == 1)
		write(STDOUT_FILENO, "$ ", 2);
		len = _getline(&buff, &buff_size, stdin);

			if (len < 0)
		{
			if (mode == 1)
			perror("getline error");
			free(buff);
			exit(0);
		}
		if (len > 0 && buff[len - 1] == '\n')
		{
			buff[len - 1] = '\0';
		}
		parser(buff, argv, delimiter);

		if (argv[0] == NULL)
		{
			continue;
		}
			if (_builtin(buff, argv) != 0)
			{
				free_argv(argv);
				free(buff);
				continue;
			}
			else
			{
				path = get_location(argv[0], av[0]);
				if (path == NULL)
				{
					/* error_note(av[0], argv[0]);*/
					free_argv(argv);
					free(buff);
					continue;
				}

				c_execute(av, path, argv, env);
			}
		free_argv(argv);
		}
	return (0);
}

