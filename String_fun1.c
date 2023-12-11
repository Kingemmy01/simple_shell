#include "shell.h"

/**
* _strcpy - copies a string to another
* @d: the destination
* @s: the source
*
* Return: pointer to destination
*/
char *_strcpy(char *d, const char *s)
{
	int len;

	for (len = 0; s[len] != '\0'; ++len)
	{
		d[len] = s[len];
	}
	d[len] = '\0';
	return (d);
}

/**
 * _strlen -returns  string length
 * @st: input string
 * Return: number chars
 */
size_t _strlen(const char *st)
{
	int i = 0;

	if (!st)
		return (0);

	while (*st++)
		i++;
	return (i);
}


/**
* my_strcat - concatenates the
* destination string and the source string
* @dest: the destination buffer
* @src: the source buffer
*
* Return: pointer to destination buffer
*/
char *my_strcat(char *dest, const char *src)
{
	char *i = dest;

	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';
	return (i);
}

/**
* my_strdup - function that duplicates a strings
* @str: the given string to duplicate
*
* Return: pointer to the duplicated string
*/
char *my_strdup(const char *str)
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

/**
* _strcmp -  compares two strings
* @str1: the 1st string to compare
* @str2: the 2nd string to compare
*
* Return: negative if str1 is less,
* positive if greater, 0 if equal
*/
int _strcmp(const char *str1, const char *str2)
{
	int i;
	int r = 0;

	for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
	{
		if (str1[i] != str2[i])
		{
			r = str1[i] - str2[i];
			break;
		}
	}

	return (r);
}

