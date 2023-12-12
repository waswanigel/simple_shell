#include "miShell.h"

int (*builtin_func)(char **args, char **front);

/**
 * tokenizer - splits commands from std input
 * cmd: the command from standard input
 * Return: tokenized commands
 */
char **tokenizer(char *cmd)
{
	char **commands;
	char *token;
	int num;

	if (cmd[0] == ' ' && cmd[_strlen(cmd)] == ' ')
		exit (0);
	if (cmd == NULL)
		return (NULL);
	commands = malloc(sizeof(char *) * 1024);
	
	if (!commands)
	{
		free(commands);
		perror("hsh");
		return (NULL);
	}
	token = strtok(cmd, " ");

	while (token)
	{
		commands[num] = _strdup(token);
		num++;
		token = strtok(NULL, " ");
	}
	commands[num] = NULL;

	return (commands);
}

/**
 * commands_handler: processes input commands
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
	if (!func[i].f)
	{
		char err_msg[] = "command not found\n";
		write(STDERR_FILENO, err_msg, _strlen(err_msg));
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
		execvp(tokens[0], tokens);
		perror("Error");
		exit(1);
	}
	else
		waitpid(child_pid, NULL, 0);
}
