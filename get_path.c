#include "shell.h"

/**
 * get_path - gets path of command
 * @command: the input command
 */
char *get_path(char *command)
{
	char *path = getenv("PATH");
	char *path_cpy = strdup(path);
	char *delim = ":";
	char buff[BUFF_SIZE];
	char *token = strtok(path_cpy, delim);

	while (token != NULL)
	{
		strcpy(buff, token);
		if (buff[strlen(buff) - 1] != '/')
		{
			strcat(buff, "/");
		}
		strcat(buff, command);
		if (access(buff, F_OK | X_OK) == 0)
		{
			free(path_cpy);
			return (strdup(buff));
		}
		token = strtok(NULL, delim);
	}
	free(path_cpy);
	return (NULL);
}
