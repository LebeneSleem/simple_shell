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
#define Max_Arguments 1000


void swap_int(int *a, int *b);
void bubble_sort(int *array, size_t size);
void remove_trailing_newline(char *inputptr);
void tokenize_arguments(char *inputptr, char **args);
void handle_command_path(char **args);
void handle_command_execution(char **args);
void handle_shell(void);

/**customs functions*/
char *_strdup(char *str);
#endif
