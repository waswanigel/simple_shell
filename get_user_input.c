#include "miShell.h"

/**
 * get_user_input - prompts user command input & display prompt after execution
 * Return: NULL
 */
void get_user_input()
{
	char *inputPrompt = "#miShell$ ";
	size_t ln = _strlen(inputPrompt);
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t buff;
	int exit_flag = 0;

	/** int interactive = isatty(STDIN_FILENO); */

	while (!exit_flag)
	{
		/** if (interactive)
		{
			write(STDOUT_FILENO, inputPrompt, ln);
			fflush(stdout);
		} */

		while (1)
		{
			write(STDOUT_FILENO, inputPrompt, ln);
			fflush(stdout);

			lineptr = (char *)malloc(sizeof(char) * 1024);

			if (!lineptr)
			{
				perror("Error allocating memory");
				exit(EXIT_FAILURE);
			}

			buff = getline(&lineptr, &n, stdin);

			if (buff == -1)
			{
				write(STDOUT_FILENO, "Exiting", 7);
				write(STDOUT_FILENO, "Exiting\n", 8);
				free(lineptr);
				exit(EXIT_SUCCESS);

			}
			if (_strcmp(lineptr, "exit\n") == 0)
			{
				exit_flag = 1;
				break;
			}
			commands_handler(lineptr);
			free(lineptr);
		}
	}
}
