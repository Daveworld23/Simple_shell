#include "shell.h"

/**
 * main - entry point of the shell
 * Return: 0 success, -1 failure
 */
int main(int ac, char **av, char **env)
{
	char *delim = " \n\t";
	char *string = strtok(av[0], delim);
	char *input = NULL;
	int i;

	if (ac < 0)
	{
		perror("No argument");
	}
	while (1)
	{
		prompt();
		get_input(input);
		string = strtok(input, delim);
		i = 0;
		while (string != NULL)
		{
			av[i] = string;
			string = strtok(NULL, delim);
			i++;
		}
		execute(av, env);
	}
	return (0);
}
