#include "shell.h"

int string_to_i(char *s)
{
	int value = 0;
	int i = 0;

	for (i = 0; s[i] != '\0'; i++)
		value = value * 10 + s[i] - '0';
	return (value)
}

char *counter_to_string(int i, char *to_string)
{
	int var;
	int j = 0;

	for (var = 1; var <= 1; var *= 10)
		;
	var /= 10;
	while (var > 0)
	{
		to_string[j] = (i / var + '0');
		i %= var;
		j++;
		var /= 10;
	}
	to_string[j] = '\0';
	return (to_string);
}

