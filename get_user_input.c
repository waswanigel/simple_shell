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
<<<<<<< HEAD

	int interactive = isatty(STDIN_FILENO);

	while (1)
	{
		if (interactive)
		{
			write(STDOUT_FILENO, inputPrompt, ln);
			fflush(stdout);
		}

=======

	while (1)
	{
		write(STDOUT_FILENO, inputPrompt, ln);
		fflush(stdout);
>>>>>>> 6092a6617bba88515ee72d2fee41c5f65fbce3fa
		buff = getline(&lineptr, &n, stdin);

		if (buff == -1)
		{
<<<<<<< HEAD
			write(STDOUT_FILENO, "Exiting", 7);
=======
			write(STDOUT_FILENO, "Exiting\n", 8);
>>>>>>> 6092a6617bba88515ee72d2fee41c5f65fbce3fa
			break;
		}
		commands_handler(lineptr);

	}
	free(lineptr);
}
