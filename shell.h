#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;
#define MAX_INPUT_SIZE 1024
#define MAX_ARGS 62
#define BUFF_SIZE 1024

void prompt(void);
void get_input(void);
char *get_path(char *command);
void execute(char **av);
int main(void);/**int ac, char **av, char **env);*/
void builtin_exit(char *arg);
void builtin_cd(char *arg);
void builtin_env(void);

#endif /* SHELL_H */
