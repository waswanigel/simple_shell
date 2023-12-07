#ifndef MISHELL_H
#define MISHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

void get_user_input();
int _strlen(char *s);
size_t _strcspn(const char *s, const char *reject);
void commands_handler(char *cmd);
int miShell_exit(char **args, char **arg_start);
int _atoi(char *s);
int (*call_builtin(char *command))(char **args, char **front);
int _strcmp(char *s1, char *s2);

typedef struct builtins_shell {
	char *name;
	int (*f)(char **argv, char **front);
} builtIns;

#endif /** MISHELL_H */
