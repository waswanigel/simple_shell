#include "miShell.h"

/**
 * miShell_exit - implements the exit builtin
 * @args: array of arguments
 * @arg_start: ptr to start of array containing arguments
 * Return: -1 if exit succeeds
 */

int miShell_exit(char **args, char **arg_start)
{
	int exit_status = 0;

	if (args[0] != NULL)
	{
		exit_status = _atoi(args[0]);

		if (exit_status == 0 && args[0][0] != '0')
		{
			write(STDERR_FILENO, "Invalid exit status: ",
					_strlen("Invalid exit status: "));
			write(STDERR_FILENO, args[0], _strlen(args[0]));
			write(STDERR_FILENO, "\n", 1);

			free(args);
			free(arg_start);
			exit(2);
		}
	}

	else
	{
		free(args);
		free(arg_start);
		return (-1);
	}
	exit(exit_status);
}
