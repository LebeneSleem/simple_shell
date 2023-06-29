#include "shell.h"

/**
*tokenize_arguments - tokenizes arguments passed by the user to the prompt
*@inputptr: pointer t the array of string or argument
*@args: array of argument
*/

void tokenize_arguments(char *inputptr, char **args)
{
	int a = 0;
	char *token;

	token = strtok(inputptr, " ");

	while (token != NULL && a < Max_Arguments - 1)
	{
		args[a++] = _strdup(token);
		token = strtok(NULL, " ");
	}
	args[a] = NULL;
}
