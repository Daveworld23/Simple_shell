#include "shell.h"

#define MAX_ARGS 1024

/**
 * main - entry point of the shell
 * Return: 0 success, -1 failure
 */
int main(void)/**char **av, char **env)*/
{
	char *input[MAX_INPUT_SIZE];
	char *delim = " \n\t";
	char *string = NULL;
	char *args[MAX_ARGS];
	int arg_count = 0;

	/**if (ac < 2)
	{
		perror("No argument");
	}*/
	while (1)
	{
		prompt();
		get_input(input);
		string = strtok(input, delim);
		while (string != NULL && arg_count < MAX_ARGS)
		{
			args[arg_count++] = string;
			string = strtok(NULL, delim);
		}
		args[arg_count] = NULL;
		if (strcmp(args[0], "cd") == 0)
			builtin_cd(args[1]);
		else if (strcmp(args[0], "exit") == 0)
			builtin_exit(args[1]);
		else if (strcmp(args[0], "env") == 0)
			builtin_env();
		else
		{
			execute(args[0], environ);
		}
	}
	return (0);
}
