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

	if (execve(args[0], args, NULL) == -1)
	{
		perror(args[0]);
	}
}

/**
 * call_builtin - matches the built-in command
 * @cmd: the command
 *
 * Return: function pointer
 */
int (*call_builtin(char *command))(char **args, char **front)
{
	int i;
	builtIns func[] = {
		{"exit", miShell_exit},
		{NULL, NULL}
	};
	
	for (i = 0; func[i].name; i++)
	{
		if (_strcmp(func[i].name, command) == 0)
			break;
	}
	return (func[i].f);
}
