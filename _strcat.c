#include "holberton.h"
/**
 * *_strcat - calls function
 * @dest: concatenated string
 * @src: original strings
 * Description: Function that concatenates two strings.
 * Return: 0
 */
char *_strcat(char *dest, char *src)
{
	char *tmp = dest;

	while (*tmp)
	{
		tmp++;
	}
	while (*src)
	{
		*tmp = *src;
		src++;
		tmp++;
	}
	*tmp = '\0';
	return (dest);
}
