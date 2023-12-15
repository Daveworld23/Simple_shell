#include "shell.h"

/**
 * prompt - displays the shell prompt for input
 *
 */
void prompt(void)
{
	char prompt[] = "shell$ ";

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}

/**
 * get_input - gets inputs
 */
void get_input(void)
{
	char *buff;
	size_t n = 0;
	ssize_t s;

	buff = malloc(sizeof(char) * n);
	s = getline(&buff, &n, stdin);
	if (s == -1)
	{
		if (feof(stdin))
			exit(EXIT_SUCCESS);
		else
		{
			perror("ERROR IN INPUT");
			exit(EXIT_FAILURE);
		}
	}
	else if (s > 1 && buff[s - 1] == '\n')
	{
		buff[s - 1] = '\0';
	}
}
