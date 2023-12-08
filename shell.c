#include "shell.h"

/**
 * main - entry point of the shell
 * Return: 0 success, -1 failure
 */
int main(int ac, char **av, char **env)
{
	if (ac < 0)
	{
		perror("No argument");
	}
	while (1)
	{
		prompt();
		get_input(*av);
		execute(av, env);
	}
	return (0);
}
