#include "shell.h"

/**
  * _strlen - Calls function
  * @s: ...
  * Description: ...
  * Return: ...
  */
int _strlen(char *s)
{
	int length;

	length = 0;

	for (length = 0; s[length]; length++)
		;
	return (length);
}

/**
  * printenv - Calls function
  * @args: ...
  * @env: ...
  * @path_list: ...
  * @hist_list: ...
  * Description: ...
  * Return: ...
  */
int printenv(char **args, char ***env, node_t **path_1ist, node_t **hist_1ist)
{
	int i = 0;
	char **environ;
	(void) args;

	environ = *env;
	if (!environ)
		return (-1);
	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		++i;
	}
	return (0);
}

/**
  * search_path - Calls function
  * @head: ...
  * @c: ...
  * @av: ...
  * @to_string: ...
  * Description:
  * Return: ...
  */
char *search_path(list_t *head, char *c, char **av, char *to_str)
{
	list_t *node;
	char *full_command;
	char *command = str_concat("/", c);
	(void) av;
	(void) to_str;

	for (node = head; node != NULL; node = node->next)
	{
		full_command = str_concat(node->str, command);

		if (access(full_command, X_OK) == 0)
		{
			return (full_command);
		}
		free(full_command);
	}
	free(command);
	return (NULL);
}

/**
  * *_strstr -  Calls function
  * @haystack: ...
  * @needle: ...
  * Description: ...
  * Return: ...
  */
char *_strstr(char *haystack, char *needle)
{
	while (*haystack != '\0')
	{
		char *beg = haystack;
		char *occur = needle;

		while (*occur == *haystack && *occur != '\0' && *haystack != '\0')
		{
			haystack++;
			occur++;
		}
		if (*occur == '\0')
			return (beg);
		haystack = beg + 1;
	}
	return (0);
}

/**
  * char_check - Calls function
  * @s: ...
  * @in: ...
  * Description: ...
  * Return: ...
  */
int char_check(char *s, const char *in)
{
	int i;

	i = 0;
	while (*(s + i) == *(in + i) && *(s + i) != '\0' && *(in + i) != '\0')
		++i;
	if (*(in + i) == '\0')
		return (1);

	return (0);
}

/**
  * _getenv - Calls function
  * @name: name to search for
  * Description: Function that gets an environmental variable
  * Return: value of variable
  */
char *_getenv(const char *name, char **env)
{
	int i;
	char **environ;

	environ = env;

	if (!environ || !name)
		return (NULL);

	i = 0;
	while (environ[i] != 0)
	{
		if (char_check(environ[i], name))
			return (environ[i] + _strlen(name) + 1);
		++i;
	}
	return (NULL);
}

/**
  * *add_node_end - Calls function
  * @head: ...
  * @str: ...
  * Description: ...
  * Return: ...
  */
list_t *add_node_end(list_t **head, char *str)
{
	list_t *new, *i;

	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = _strdup(str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		for (i = *head; i->next != NULL; i = i->next)
			;
		i->next = new;
	}
	return (new);
}

/**
  * build_linked_list - Calls function
  * @path: ...
  * head: ...
  * Description: ...
  * Return: ...
  */
void build_linked_list(char *path, list_t **head)
{
	char *token;

	token = strtok(path, ":");
	while (token)
	{
		add_node_end(head, token);
		token = strtok(NULL, ":");
	}
}

/**
  * free_list - Calls function
  * @head: ...
  * Description: ...
  * Return: ...
  */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		free(temp->str);
		head = head->next;
		free(temp);
	}
}
