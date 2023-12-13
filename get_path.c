#include "shell.h"

/**
 * get_path - checks path of command
 */
char *get_path(char *command)
{
	char *path = getenv("PATH");
	char *delim = ":";
	size_t path_len, command_len;
	char *token;
	char *full_path;

	if (path == NULL || command == NULL)
		return (NULL);
	*token = strtok(path, delim);
	while (token != NULL)
	{
		path_len = strlen(token);
		command_len = strlen(command);
		*full_path = (char *)malloc(path_len + command_len + 2);
		if (full_path == NULL)
		{
			return (NULL);
		}
		strcpy(full_path, token);
		if (full_path[path_len - 1] != '/')
		{
			strcat(full_path, "/");
		}
		strcat(full_path, command);
		if (access(full_path, F_OK | X_OK) == 0)
		{
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
