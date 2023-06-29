#include "shell.h"

/**
*handle_command_path - finds the path of a command imputed for execution
*@args: array of string or characters that make up the command
*/

void handle_command_path(char **args)
{
	char *path, *token, *path_copy, user_command;

	if (args[0][0] != '/')
	{
		path = getenv("PATH");
		if (path != NULL)
		{
			path_copy = _strdup(path);
			token = strtok(path_copy, ":");
			while (token != NULL)
			{
				command[Max_Command];
				snprintf(user_command, sizeof(user_command), "%s/%s", token, args[0])
					if (access(user_command, X_OK) == 0)
					{
						free(args[0]);  /*frees original value*/
						args[0] = strdup(user_command);
						free(path_copy);
						returrn;
					}
				token = strtok(NULL, ":");
			}
			free(path_copy);
		}
	}
}
