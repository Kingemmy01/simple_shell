#include "shell.h"

/**
 * _getenv - it gets an environmental variabless
 * @name: This is the name of the requested variable
 * Return: returns a null-terminated string with the
 *  value of the requested environment variable
 *  or otherwise NULL
 */
char *_getenv(const char *name)
{
	size_t len = _strlen(name);
	char **env;

	for (env = environ; *env != NULL; ++env)
	{
		if (_strncmp(*env, name, len) == 0 && (*env)[len] == '=')
		{
			return (*env + len + 1);
		}
	}
	return (NULL);
}

/**
 * _strchr - a function that returns a string
 * when it find a char c
 * @str: the string mixed with a delimiter c
 * @c: the delimiter
 * Return: pointer to the delimter c
 */
char *_strchr(const char *str, int c)
{

	while (*str != '\0')
	{
		if (*str == c)
		{
			return ((char *)str);
		}
		str++;
	}
	if (c == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

/**
 * _env - to display the env variable
 */
void _env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

