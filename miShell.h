#ifndef MISHELL_H
#define MISHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <linux/limits.h>
#include <fcntl.h>

void get_user_input();
int _strlen(char *s);
size_t _strcspn(const char *s, const char *reject);
void commands_handler(char *cmd);
void cmd_executor(char **tokens);
int miShell_exit(char **args, char **arg_start);
int _atoi(char *s);
int (*call_builtin(char *command))(char **args, char **front);
int _strcmp(char *s1, char *s2);

typedef struct builtins_shell {
	char *name;
	int (*f)(char **argv, char **front);
} builtIns;

/** MORE STRING FUNCTIONS */
int _putchar(char c);
void _puts(char *s);
int _isalpha(int ch);
char *_itoa(unsigned int n);
char *_strdup(char *s);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strchr(char *str, char c);
char *_strcat(char *str1, char *str2);
char *_strncpy(char *dest, char *src, int n);
char *_strcpy(char *dest, char *src);
void rev_arr(char *arr, int l);
int intlength(int n);
char **tokenizer(char *cmd);

#endif /** MISHELL_H */
