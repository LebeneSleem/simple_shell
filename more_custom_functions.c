#include "shell.h"

/**
  * _atoi - Convert a string to an integer
  * @s: The pointer to convert
  * Return: An integer
  */
int _atoi(char *s)
{
	int a = 0;
	unsigned int ni = 0;
	int min = 1;
	int isi = 0;

	while (s[a])
	{
		if (s[a] == 45)
		{
			min *= -1;
		}
		while (s[a] >= 48 && s[a] <= 57)
		{
			isi = 1;
			ni = (ni * 10) + (s[a] - '0');
			a++;
		}
		if (isi == 1)
		{
			break;
		}
		a++;
	}
	ni *= min;
	return (ni);
}

/**
  * _strlen - Returns the length of a string
  * @s: The string to get the length of
  * Return: The length of @s
  */
int _strlen(char *s)
{
	int length = 0;

	while (*s++)
		length++;
	return (length);
}

/**
  * _strcpy - Copy a string
  * @dest: Destination value
  * @src: Source value
  * Return: the pointer to dest
  */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i++] = '\0';
	return (dest);
}

/**
  * _strncpy - Copy a string
  * @dest: The buffer storing the string copy
  * @src: The source string
  * @n: The maximum number of bytes to copy
  * Return: A pointer to the resulting string destination
  */
char *_strncpy(char *dest, char *src, int n)
{
	int index = 0, src_len = 0;

	while (src[index++])
		src_len++;
	for (index = 0; src[index] && index < n; index++)
		dest[index] = src[index];
	for (index = src_len; index < n; index++)
		dest[index] = '\0';
	return (dest);
}

/**
  * _strncat - Concatenate two strings using at most
  * an inputted number of bytes from src
  * @dest: The string to be appended
  * @src: The string to be appended to dest
  * @n: The number of bytes from src to be appended to dest
  * Return: A pointer to the resulting string destination
  */
char *_strncat(char *dest, char *src, int n)
{
	int index = 0, dest_len = 0;

	while (dest[index++])
		dest_len++;
	for (index = 0; src[index] && index < n; index++)
		dest[dest_len++] = src[index];
	return (dest);
}

