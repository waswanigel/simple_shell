#include "miShell.h"

/**
 * get_user_input - prompts user command input & display prompt after execution
 * Return: NULL
 */
void get_user_input()
{
	char *inputPrompt = "#miShell$ ";
	size_t ln = _strlen(inputPrompt);
	char *lineptr;
	size_t n = 0;

	while (1)
	{
		write(STDOUT_FILENO, inputPrompt, ln);
		fflush(stdout);
		getline(&lineptr, &n, stdin);
		commands_handler(lineptr);

	}
	free(lineptr);
}
