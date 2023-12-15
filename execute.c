#include "shell.h"

/**
 * execute - executes the program
 */
void execute(char **av)
{
	pid_t ch_pid;
	int status;
	/**char *cmdpath;**/

	ch_pid = fork();
	if (ch_pid == -1)
	{
		perror("fork failed");
		exit(EXIT_FAILURE);
	}
	else if (ch_pid == 0)
	{
		/**cmdpath = get_path(av[0]);**/
		/** env = environ;*/
		if (execve(av[0], av, environ) == -1)
		{
			perror("Execution failed");
			/**free(cmdpath);**/
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
}
