#include "miShell.h"
/**
 * commands_handler: processes input commands
 * @cmd: the command
 */

void commands_handler(char *cmd)
{

	size_t newline_index = _strcspn(cmd, "\n");

	char *args[64];
	int idx = 0;
	char *token;

	cmd[newline_index] = '\0';

	token = strtok(cmd, " ");

	while (token != NULL && idx < 63)
	{
		args[idx++] = token;
		token = strtok(NULL, " ");
	}
	args[idx] = NULL;

	execve(args[0], args, NULL);

	perror(args[0]);
}
