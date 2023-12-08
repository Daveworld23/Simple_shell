#include "shell.h"

/**
 * prompt - displays the shell prompt for input
 *
 */
int prompt(void)
{
	char prompt[] = "shell$ ";

	while (1)
	{
		write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
	}
	return (0);
}

void get_input(char *buff)
{
	char *str = NULL;
	size_t n = 0;
	ssize_t s;

	while(*buff)
	{
		s = getline(&buff, &n, stdin);
		if (s == -1)
		{
			perror("ERROR IN INPUT");
			free(str);
			exit(EXIT_FAILURE);
		}
		else if (s == 1)
			continue;
		else if (str[n - 1] == '\n')
		{
			str[n - 1] = '\0';
		}
	}
}
