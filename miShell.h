#ifndef MISHELL_H
#define MISHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


void get_user_input();
int _strlen(char *s);
size_t _strcspn(const char *s, const char *reject);
void commands_handler(char *cmd);

#endif /** MISHELL_H */
