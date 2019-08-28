#include "shell.h"

/**
 * word_counter - Calls Function
 * @str: ...
 * Description: ...
 * Return: ...
 */
int word_counter(char *str)
{
	int i, count = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
			count++;
	}
	return (count);
}

/**
 * command_prompt - Calls function
 * Description: Function that prints command prompt
 * Return: 0
 */
void command_prompt()
{
	signal(SIGINT, signal_control);
	if (isatty(0) == 1)
		write(STDOUT_FILENO, "$ ", 2);
}

/**
 * read_command - Calls function
 * @
 * @
 * Description: Function that parses and interprets user input
 * Return: 0
 */


/*
void read_command(char argv[], char **argv)

void read_command()
{
	int i, counter = 1;
	char *buf;
	char **argv = NULL;
	size_t buf_size;

	if (getline(&buf, &buf_size, stdin) == EOF)
	{
		if (isatty(0) == 1)
			write(STDOUT_FILENO, "\n", 1);
		break;
	}
	i = _strlen(buf);
	if (i > 1)
		buf[i - 1] = '\0';
	argv = split_string(buf);
	if (!argv)
	{
		counter++;
		continue;
	}
}
*/
int read_command(char *buf) {

	int i, counter = 1;
	/*char *buf; */
	char **argv = NULL;
	size_t buf_size;

	if (getline(&buf, &buf_size, stdin) == EOF) {
		if (isatty(0) == 1)
			write(STDOUT_FILENO, "\n", 1);
	}
	i = _strlen(buf);
	if (i > 1)
		buf[i - 1] = '\0';

	argv = split_string(buf);
	if (!argv) {
		counter++;
	}
	return (buf_size);
}

