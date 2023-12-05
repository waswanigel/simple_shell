#include "miShell.h"

/**
 * _strlen - returns length of a string
 * @s: the string
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;
	int count = 0;

	while (s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}
