#ifndef _SHELL_H_
#define _SHELL_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* */
typedef struct node_s
{
	char *name;
	char *val;
	struct node_s *next;
} node_t;

/* */
typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;

/* */
typedef struct shell_s
{
	char **environ;
	node_t *path_list;
	node_t *hist_list;
	char **args;
	char *rest;
} shell_t;

/* */
typedef struct builtin_sh
{
	char *name;
	char *extra;
	int (*fp)(char **args, char **env, node_t **path_list, node_t **hist_list);
} builtin_t;




void free_list(list_t *head);
void build_linked_list(char *path, list_t **head);
void exit_toobig(char **av, char **argv, char *to_string);
void err_handler(char **av, char **argv, char *to_string);

int word_counter(char *str);

/* Functions in conversions.c file */
int string_to_int(char *s);
char *counter_to_string(int i, char *to_string);

/* Functions in pathfuncs.c file */
int printenv(char **args, char ***env, node_t **path_list, node_t **hist_list);
char *search_path(list_t *head, char *c, char **av, char *to_string);
char *_strstr(char *haystack, char *needle);
int char_check(char *s, const char *in);
char *_getenv(const char *name, char **env);
list_t *add_node_end(list_t **head, char *str);
void build_linked_list(char *path, list_t **head);
void free_list(list_t *head);

/* Functions in strops.c file */
int _strlen(char *s); /* Do we need both? */
int word_count(char *str);
char **split_string(char *str);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);

/* Functions that need to be put in separete files */
void exit_help(char **av, char **argv, char *to_string);
void error_help(char **av, char **argv, char *to_string);
extern char **environ; /* Duplicate */
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(const char *name);
extern char **environ; /* Duplicate */
char *_memcpy(char *dest, const char *src, unsigned int n);
int _strncmp(char *s1, char *s2, size_t bytes);
char *_strdup(char *str);

#endif /* SHELL_H */
