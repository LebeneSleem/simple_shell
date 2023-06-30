#include "shell.h"

/**
*handle_command_execution - executes a command passed
*@args: array of string of command
*/
void handle_command_execution(char **args)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		handle_command_path(args);
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
