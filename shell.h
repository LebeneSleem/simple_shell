#ifndef SHELL_H_
#define SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>


#define BUFFER_SIZE 1024
#define Max_Arguments 20
#define PATH_MAX 100

void swap_int(int *a, int *b);
void bubble_sort(int *array, size_t size);

/**
 * struct RuntimeData - Struct that contains all relevant data during runtime
 * @arg_vector: Argument vector
 * @user_input: Command line written by the user
 * @arguments: Tokens of the command line
 * @exit_status: Last exit status of the shell
 * @line_counter: Line counter
 * @environment: Environment variables
 * @process_id: Process ID of the shell
 */
typedef struct RuntimeData
{
    char **arg_vector;
    char *user_input;
    char **arguments;
    int exit_status;
    int line_counter;
    char **environment;
    char *process_id;
} RuntimeDataShell;

/**
 * struct SeparatorNode - Single linked list node to store separators
 * @separator_char: Separator character (;, |, or &)
 * @next: Pointer to the next node
 * Description: Single linked list to store separators in a command line
 */
typedef struct SeparatorNode
{
    char separator_char;
    struct SeparatorNode *next;
} SeparatorNode;

/**
 * struct CommandLineNode - Single linked list node to store command lines
 * @command_line: Command line
 * @next: Pointer to the next node
 * Description: Single linked list to store command lines
 */
typedef struct CommandLineNode
{
    char *command_line;
    struct CommandLineNode *next;
} CommandLineNode;

/**
 * struct VariableNode - Single linked list node to store variables
 * @variable_length: Length of the variable
 * @value: Value of the variable
 * @value_length: Length of the value
 * @next: Pointer to the next node
 * Description: Single linked list to store variables
 */
typedef struct VariableNode
{
    int variable_length;
    char *value;
    int value_length;
    struct VariableNode *next;
} VariableNode;

/**
 * struct BuiltinCommand - Builtin struct for command arguments
 * @command_name: The name of the builtin command (e.g., cd, exit, env)
 * @function: Pointer to the function that handles the command
 */
typedef struct BuiltinCommand
{
    char *command_name;
    int (*function)(RuntimeDataShell *runtime_data);
} BuiltinCommand;

#endif
