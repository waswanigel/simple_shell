#include "miShell.h"

/**
 * _strcspn - finds the length of the initial segment of a string that does
 *		not contain any character from a given set of characters
 * @s: input string
 * @rejectSet: string checked against
 *
 * Return: length of the segment that doesn’t contain any matching xters
 */

size_t _strcspn(const char *str, const char *rejectSet)
{
	size_t len = 0;
	const char *j;
	while (*str)
	{
		j = rejectSet;
		while (*j)
		{
			if (*str == *j)
			{
				return (len);
			}
			j++;
		}
		str++;
		len++;
	}
	return (len);
}
