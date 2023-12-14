#include "miShell.h"

/**
 * handle_non_interactive_mode - handles non interactive mode
 * Return: NULL
 */
void handle_non_interactive_mode(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t buff;

	lineptr = (char *)malloc(sizeof(char) * 1024);

	if (!lineptr)
	{
		perror("memory allocation error");
		exit(EXIT_FAILURE);
	}

	buff = getline(&lineptr, &n, stdin);

	if (buff == -1)
	{
		perror("hsh: read error");
		free(lineptr);

		exit(EXIT_FAILURE);
	}

	commands_handler(lineptr);
	free(lineptr);
}

/**
 * interactive_mode - handles interactive mode
 */

void interactive_mode(void)
{
	char *inputPrompt = "#miShell$ ";
	size_t ln = _strlen(inputPrompt);
	char *lineptr = NULL;
	size_t n = 0;
	int exit_flag = 0;
	ssize_t buff;

	while (!exit_flag)
	{
		write(STDOUT_FILENO, inputPrompt, ln);
		fflush(stdout);

		lineptr = (char *)malloc(sizeof(char) * 1024);

		if (!lineptr)
		{
			perror("memory allocation error");
			exit(EXIT_FAILURE);
		}

		buff = getline(&lineptr, &n, stdin);

		if (buff == -1)
		{
			write(STDOUT_FILENO, "Exiting\n", 8);
			free(lineptr);
			exit(EXIT_SUCCESS);
		}

		if (_strcmp(lineptr, "exit\n") == 0)
		{
			exit_flag = 1;
			free(lineptr);
			continue;
		}

		commands_handler(lineptr);
		free(lineptr);
	}
}

/**
 * get_user_input - prompts user command input & display prompt after execution
 */

void get_user_input(void)
{
	int interactive = isatty(STDIN_FILENO);

	if (!interactive)
	{
		handle_non_interactive_mode();
	}
	else
	{
		interactive_mode();
	}
}
