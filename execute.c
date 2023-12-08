#include "shell.h"

/**
 * execute - executes the program
 */
void execute(char *av[], char **env)
{
	pid_t ch_pid;
	int status, i = 0;
	char *delim = " \n\t", *token = NULL;

	token = strtok(av[i], delim);
	while (av[i])
	{
		av[++i] = strtok(NULL, delim);
	}
	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("fork failed");
		free(token);
		exit(EXIT_FAILURE);
	}
	if (ch_pid == 1)
	{
		if (execve(av[0], av, env) == -1)
		{
			perror("Execution fauled");
			exit(EXIT_FAILURE);
		}
	}
	else
		wait(&status);
}
