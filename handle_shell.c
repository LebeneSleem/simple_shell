#include "shell.h"

/**
*handle_shell - prints prompt, takes in input and executes
*/
void handle_shell(void)
{
	char *inputptr = NULL;
	size_t n = 0;
	ssize_t user_input;
	char *args[Max_Arguments], **environ_ptr;
	int a;
	extern char **environ;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "Simple shell$ ", 14);
		}
		user_input = getline(&inputptr, &n, stdin);
		if (user_input == -1)
		{
			if (isatty(STDIN_FILENO))
			{
				perror("error");
			}
			break;
		}
		remove_trailing_newline(inputptr);
		tokenize_arguments(inputptr, args);

		if (strcmp(args[0], "exit") == 0)
		{
			for (a = 0; args[a] != NULL; a++)
			{
				free(args[a]);
			}
			free(inputptr);
			handle_shell_exit(args[1]);
		}
		else if (strcmp(args[0], "env") == 0)
		{
			environ_ptr = environ;
			while (*environ_ptr != NULL)
			{
				write(STDOUT_FILENO, *environ_ptr, strlen(*environ_ptr));
				write(STDOUT_FILENO, "\n", 1);
				environ_ptr++;
			}
		}
		else
		{
			handle_command_execution(args);
		}
		/* Free allocated memory for arguments*/
		for (a = 0; args[a] != NULL; a++)
		{
			free(args[a]);
		}
	}
	free(inputptr);
}
