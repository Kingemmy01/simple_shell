#include "shell.h"

/**
 * get_location - funtion that find the location of the path
 * @argv: argument vector
 * @av: argument count
 *
 * Return: NULL if it finds the exact location of the path
 */

char *get_location(const char *argv, const char *av)
{
	char *path, *full_path;

	if (_strchr(argv, '/') != NULL)
	{
	return (_strdup(argv));
	}

	path = _getenv("PATH");

	if (path == NULL)
	{
	return (NULL);
	}

	full_path = path_place(path, argv, av);

	free(path);

	return (full_path);
}

/**
 * path_place -  funtion to search for a fle in the path
 *
 * @path: the path
 * @argv: the argument vector
 * @av: Argument count
 *
 * Return: NULL char if it finds the exact file
 */

char *path_place(const char *path, const char *argv, const char *av)
{
	char *token;
	char *path_copy = _strdup(path);

	(void)*av;

	if (path_copy == NULL)
	{
	return (NULL);
	}

	token = _strtok(path_copy, ":");

	while (token != NULL)
	{
	char *full_path = (char *)malloc(_strlen(token) + _strlen(argv) + 2);

	if (full_path == NULL)
	{
		free(path_copy);
		return (NULL);
	}
	_strcpy(full_path, token);
	my_strcat(full_path, "/");
	my_strcat(full_path, argv);

	if (access(full_path, X_OK) == 0)
	{
		free(path_copy);
		return (full_path);
	}

	free(full_path);
	token = _strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
