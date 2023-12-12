#include "miShell.h"

/**
 * _strcmp - compares 2 strings
 * @str1: string 1
 * @str2: string 2
 * Return: 0 or difference
 */
int _strcmp(char *str1, char *str2)
{
	int check = 0, i, l1, l2;

	l1 = _strlen(str1);
	l2 = _strlen(str2);

	if (str1 == NULL || str2 == NULL)
		return (1);

	if (l1 != l2)
		return (1);

	for (i = 0; str1[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			check = str1[i] - str2[i];
			break;
		}
		else
			continue;
	}
	return (check);
}

/**
 * _strcat - concatenates 2 strings
 * @str1: string 1
 * @str2: string 2
 * Return: concatenated string
 */
char *_strcat(char *str1, char *str2)
{
	char *s = str1;

	while (*str1 != '\0')
	{
		str1++;
	}
	while (*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';
	return (s);
}

/**
 * _strdup - duplicate string
 * @s: string
 * Return: duplicate str/ NULL on failure
 */
char *_strdup(char *s)
{
	size_t l, i;
	char *s2;

	l = _strlen(s);
	s2 = malloc(sizeof(char) * (l + 1));

	if (!s2)
	{
		return (NULL);
	}
	for (i = 0; i <= l; i++)
	{
		s2[i] = s[i];
	}
	return (s2);
}

/**
 * _strncmp - compares n characters of two strings
 * @str1: string 1
 * @str2: string 2
 * @n: amount of characters
 * Return: 1 or 0
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	if (str1 == NULL)
		return (-1);
	for (i = 0; i < n && str2[i]; i++)
	{
		if (str1[i] != str2[i])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strchr - locates a char in a string
 * @str: string
 * @c: the char
 * Return: ptr to the character
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
		{
			break;
		}
	} while (*str++);
	return (str);
}
