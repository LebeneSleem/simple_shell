#include "shell.h"
/**
*custom_getline - function that works as the standard getline function
*@lineptr: pointer to the array
@n: holds the size of the memory
@stream: location or file read from
*Return: number of characters read
*/
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	static char *Buffer = NULL;
	char *temp;
	static size_t Buffer_Size = 0;
	static size_t Buffer_index = 0;
	int c;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	while ((c = getchar()) != '\n' && c != EOF)
	{
		if (Buffer_index == Buffer_Size) 
		{
			Buffer_Size += 10;
			temp = realloc(Buffer, Buffer_Size);
			if (temp == NULL)
			{
				free(Buffer);
				return (-1);
			}
			Buffer = temp;
		}
		Buffer[Buffer_index++] = c;
	}
	if (c == EOF && Buffer_index == 0)
	{
		free(Buffer);
		return (-1);
	}
	Buffer[Buffer_index] = '\0';
	*lineptr = Buffer;
	*n = Buffer_Size;
	return (Buffer_index);
}

