#include "shell.h"

/**
 * _strncmp - string n compare function
 * @str1: This is the first string to be compared
 * @str2: This is the 2nd string to be compared
 * @n: The maximum number of characters to be compared
 *
 * Return: 0 on success
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t c;

	for (c = 0; c < n; ++c)
	{
		if (str1[c] != str2[c])
		{
			return ((int)(unsigned int)str1[c] - (int)(unsigned int)str2[c]);
		}
		if (str1[c] == '\0')
		{
			return (0);
		}
	}
	return (0);
}

/**
* _strdup - function that duplicates a strings
* @str: the given string to duplicate
*
* Return: pointer to the duplicated string
*/
char *_strdup(const char *str)
{
	int i, len = 0;
	char *res;

	if (str == NULL)
		return (NULL);

	while (str[len] != '\0')
		len++;

	res = (char *)malloc((len + 1) * sizeof(char));

	if (res == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
		res[i] = str[i];

	return (res);
}

