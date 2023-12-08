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
#define BUFF_SIZE 1024;
#define MAX_COMMAND 10;
#define MAX_INPUT_SIZE 1024;

void prompt(void);
void get_input(char *buff);
void execute(char *av[], char **env);
int main(int ac, char **av, char **env);

#endif /* SHELL_H */
