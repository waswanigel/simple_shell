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
	ssize_t buff;

	while (1)
	{
		write(STDOUT_FILENO, inputPrompt, ln);
		fflush(stdout);
		buff = getline(&lineptr, &n, stdin);

		if (buff == -1)
		{
			write(STDOUT_FILENO, "Exiting\n", 8);
			break;
		}
		commands_handler(lineptr);

	}
	free(lineptr);
}
