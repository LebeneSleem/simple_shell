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

/**
  * _strcmp - Compare two strings
  * @s1: A pointer to the first string to be compared
  * @s2: A pointer to the second string to be compared
  * Return: If str1 < str2, the negative difference of the first unmatched char
  * If str1 == str2, 0
  * If str1 > str2, the positive difference of the unmatched characters
  */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
  * _strcat - Concatenate two strings
  * @dest: The destination string
  * @src: The source string
  * Return: A pointer to the resulting string destination
  */
char *_strcat(char *dest, char *src)
{
	int dlen = 0, i;

	while (dest[dlen])
	{
		dlen++;
	}
	for (i = 0; src[i] != 0; i++)
	{
		dest[dlen] = src[i];
		dlen++;
	}
	dest[dlen] = '\0';
	return (dest);
}

/**
  * _memcpy - Entry
  * @dest: input memory area
  * @src: memory area
  * @n: number of bytes to be copied
  * Return: pointer to dest
  */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int c;

	for (c = 0; c < n; c++)
		dest[c] = src[c];
	return (dest);
}

/**
  * _isdigit - Check for a digit
  * @i: The number to be checked
  * Return: 1 for a character that is a digit or 0 for any else
  */
int _isdigit(int i)
{
	if (i >= 48 && i <= 57)
	{
		return (1);
	}
	return (0);
}


