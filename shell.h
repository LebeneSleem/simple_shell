#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>

extern char **environment;

#define BUFFER_SIZE 1024
#define Mac_Arguments 1000
#define PATH_MAX 100

void swap_int(int *a, int *b);
void bubble_sort(int *array, size_t size);
void remove_trailing_newline(char *inputptr);
void tokenize_arguments(char *inputptr, char **args);
void find_executable_command(char **args);
void handle_command_execution(char **args);
void handle_shell();


#endif
