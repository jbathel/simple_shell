#include "shell.h"
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int _strlen(char *s)
{
	unsigned int length;

	length = 0;
	for (length = 0; s[length]; length++)
		;
	return (length);
}



int word_count(char *str)
{
	int i, count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}


char **split_string(char *str)
{
	int i, w_count;
	char *token;
	char **words;

	w_count = word_count(str);

	if (!w_count)
		return (NULL);

	token = strtok(str, " ");

	i = 0;

	while (token)
	{
		words[i] = token;
		token = strtok(NULL, " ");
		i++;
	}
	words[i] = NULL;

	return (words);
}

int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != '\0' && s2[a] != '\0' && s1[a] == s2[a]; a++)
		;
	return (s1[a] - s2[a]);
}

char *str_concat(char *s1, char *s2)
{
	char *str;
	int i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	
	str = (char *)malloc(sizeof(char) * (_strlen(s1) + _strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	for (i = 0; s1[i]; i++)
		str[i] = s1[i];
	j = 0;
	while (s2[j] || str[i])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}


