#include "holberton.h"
/**
 * _strcmp - calls function
 * @s1: original string
 * @s2: string to compare
 * Description: Function that prints a string,
 * followed by a new line, to stdout.
 * Return: 0
 */
int _strcmp(char *s1, char *s2)
{
	for ( ; *s1 == *s2; s1++, s2++)
	{
		if (*s1 == '\0')
		{
			return (0);
		}
	}
	return (*s1 - *s2);
}
