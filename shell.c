#include "shell.h"

#define MAX_ARGS 1024

/**
 * main - entry point of the shell
 * Return: 0 success, -1 failure
 */
int main(char *input)/**char **av, char **env)*/
{
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
		if (strcmp(args[arg_count], "cd") == 0)
			builtin_cd(args[arg_count]);
		else if (strcmp(args[arg_count], "exit") == 0)
			builtin_exit(args[arg_count]);
		else if (strcmp(args[arg_count], "env") == 0)
			builtin_env;
		else
		{
			execute(args[arg_count], env);
		}
	}
	return (0);
}
