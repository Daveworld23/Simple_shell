#include "shell.h"

/**
 * execute - executes the program
 */
void execute(char *av[], char **env)
{
	pid_t ch_pid;
	int status;

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	if (ch_pid == 0)
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
