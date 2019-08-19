#include "holberton.h"

/**
 * str_cpy - function t hat copies the string pointed to by src
 * @dest: pointer of address of string
 * @src: pointer to string to be copied
 * Return: void.
 */

char *_strcpy(char *dest, char *src)
{
int i;

for (i = 0; src[i] != '\0'; i++)
{
dest[i] = src[i];
}
dest[i] = '\0';
return (dest);
}
