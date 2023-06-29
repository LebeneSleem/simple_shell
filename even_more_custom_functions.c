#include "shell.h"
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

