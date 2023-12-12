#include "miShell.h"

/**
 * _itoa - conv int to char
 * @n: integer
 * Return: char ptr
 */
char *_itoa(unsigned int n)
{
	int l = 0, i = 0;
	char *s;

	l = intlength(n);
	s = malloc(l + 2);

	if (!s)
	{
		free(s);
		return (NULL);
	}

	*s = '\0';

	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	rev_arr(s, l);
	s[i + 1] = '\0';

	return (s);
}
/**
 * rev_arr - reverse an array
 * @arr: array
 * @l: array lenth
 */
void rev_arr(char *arr, int l)
{
	int i;
	char temp;

	for (i = 0; i < (l / 2); i++)
	{
		temp = arr[i];
		arr[i] = arr[(l - 1) - i];
		arr[(l - 1) - i] = temp;
	}
}

/**
 * intlength - calculate integer length
 * @n: integer
 * Return: int length
 */
int intlength(int n)
{
	int l = 0;

	while (n != 0)
	{
		l++;
		n /= 10;
	}
	return (l);
}
