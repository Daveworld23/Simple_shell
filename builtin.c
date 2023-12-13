#include "shell.h"

/**
 * builtin_env - handles builtin environment variables
 */
void builtin_env(void)
{
	char **env;

	for (env = environ; env != NULL; env++)
	{
		write(STDOUT_FILENO, env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * builtin_exit - handles exit builtin
 */
void builtin_exit(char *arg)
{
	int status;

	if (arg == NULL)
	{
		exit(0);
	}
	else
	{
		status = atoi(arg);
		exit(status);
	}
}

/**
 * buildin_cd - handles change directory builtin
 */
void builtin_cd(char *arg)
{
	char *home;

	if (arg == NULL)
	{
		home = getenv("HOME");
		if (home == NULL)
		{
			write(STDERR_FILENO, "Error: Home variable not set\n", 29);
		}
		else if (chdir(home) != 0)
		{
			perror("Error changing directory");
		}
	}
	else if (chdir(arg) != 0)
	{
		perror("Error changing directory");
	}
}
