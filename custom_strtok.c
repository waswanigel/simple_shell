#include "miShell.h"

/**
 * isDelimiter - checks if a character matches any delimiter character
 * @c: character to check
 * @delimiters: string of delimiters
 * Return: 1 on success (if it's a delimiter), 0 on failure
 */
unsigned int isDelimiter(char c, const char *delimiters)
{
	unsigned int i;

	for (i = 0; delimiters[i] != '\0'; i++)
	{
		if (c == delimiters[i])
			return (1);
	}
	return (0);
}

/**
 * custom_strtok - extracts tokens from a string
 * @str: string to tokenize
 * @delim: delimiter
 * Return: pointer to the next token or NULL
 */

char *custom_strtok(char *str, const char *delim)
{
	static char *tokenPtr;
	static char *newTokenPtr;
	unsigned int i;

	if (str != NULL)
		newTokenPtr = str;
	tokenPtr = newTokenPtr;
	if (tokenPtr == NULL)
		return (NULL);
	for (i = 0; tokenPtr[i] != '\0'; i++)
	{
		if (isDelimiter(tokenPtr[i], delim) == 0)
			break;
	}
	if (newTokenPtr[i] == '\0' || newTokenPtr[i] == '#')
	{
		newTokenPtr = NULL;
		return (NULL);
	}
	tokenPtr = newTokenPtr + i;
	newTokenPtr = tokenPtr;
	for (i = 0; newTokenPtr[i] != '\0'; i++)
	{
		if (isDelimiter(newTokenPtr[i], delim) == 1)
			break;
	}
	if (newTokenPtr[i] == '\0')
		newTokenPtr = NULL;
	else
	{
		newTokenPtr[i] = '\0';
		newTokenPtr = newTokenPtr + i + 1;
		if (*newTokenPtr == '\0')
			newTokenPtr = NULL;
	}
	return (tokenPtr);
}
