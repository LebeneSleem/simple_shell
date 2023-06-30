#include "shell.h"

/**
*handle_command_path - finds the path of a command imputed for execution
*@args: array of string or characters that make up the command
*/

void handle_command_path(char **args)
{
	char *path, *token, *path_copy, command[Max_Arguments];

	if (args[0][0] != '/')
	{
		path = getenv("PATH");
		if (path != NULL)
		{
			path_copy = _strdup(path);
			token = strtok(path_copy, ":");
			while (token != NULL)
			{
				snprintf(command, sizeof(command), "%s/%s", token, args[0]);
					if (access(command, X_OK) == 0)
					{
						free(args[0]);  /*frees original value*/
						args[0] = _strdup(command);
						free(path_copy);
						return;
					}
				token = strtok(NULL, ":");
			}
			free(path_copy);
		}
	}
}
