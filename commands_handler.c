#include "miShell.h"

/**
 * tokenizer - splits commands from std input
 * @cmd: the command from standard input
 * Return: tokenized commands
 */
char **tokenizer(char *cmd)
{
	char **commands;
	char *token;
	int num = 0;

	if (cmd[0] == ' ' && cmd[_strlen(cmd)] == ' ')
		exit(0);
	if (cmd == NULL)
		return (NULL);
	commands = malloc(sizeof(char *) * 1024);

	if (!commands)
	{
		free(commands);
		perror("hsh");
		return (NULL);
	}
	token = custom_strtok(cmd, " ");

	while (token)
	{
		commands[num] = _strdup(token);
		num++;
		token = custom_strtok(NULL, " ");
	}
	commands[num] = NULL;

	return (commands);
}

/**
 * commands_handler - processes input commands
 * @cmd: the command
 */

void commands_handler(char *cmd)
{
	int i;
	char **commands = tokenizer(cmd);

	if (!commands || !commands[0])
	{
		char error_msg[] = "Invalid command\n";

		write(STDERR_FILENO, error_msg, _strlen(error_msg));
		return;
	}
	builtin_func = call_builtin(commands[0]);

	if (builtin_func != NULL)
	{
		builtin_func(commands, commands);
	}
	else
		cmd_executor(commands);

	for (i = 0; commands[i] != NULL; i++)
	{
		free(commands[i]);
	}
	free(commands);

}

/**
 * call_builtin - matches the built-in command
 * @command: the command
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

/**
 * cmd_executor - executes commands
 * @tokens: the arguments/ parsed commands
 */
void cmd_executor(char **tokens)
{
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == 0)
	{
		execve(tokens[0], tokens, NULL);
		perror(tokens[0]);
		exit(1);
	}

	else
		waitpid(child_pid, NULL, 0);
}
