#include "miShell.h"

/**
 * _atoi - converts string to integer
 * @s: the string to be converted
 *
 * Return: the integer
 */

int _atoi(char *s)
{
	unsigned int num = 0;
	int sign = 1, i =0;

	while (s[i])
	{
		for (; s[i] == '-'; i++)
		{
			sign *= -1;
		}
		if (s[i] >= 48 && s[i] <= 57)
		{
			for (; s[i] != '\0'; i++)
			{
				num = num * 10 + (s[i] - '0');
			}
			num *= sign;
		}
		else
			continue;
	}
	return (num);
}
