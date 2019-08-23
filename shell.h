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

typedef struct node_s
{
	char *name;
	char *val;
	struct node_s *next;
} node_t;

typedef struct list_s
{
	char *str;
	struct list_s *next;
} list_t;




typedef struct shell_s
{
	char **environ;
	node_t *path_list;
	node_t *hist_list;
	char **args;
	char *rest;
} shell_t;

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
int string_to_int(char *s);


int printenv(char **args, char ***env, node_t **path_list, node_t **hist_list);
extern char **environ;
int _setenv(const char *name, const char *value, int overwrite);
char *_getenv(const char *name, char **env);
int _unsetenv(const char *name);



int _strlen(const char *s);
extern char **environ;
char *_memcpy(char *dest, const char *src, unsigned int n);
int _strncmp(char *s1, char *s2, size_t bytes);
int char_check(char *s, const char *in);
char *_strdup(char *str);
char **split_string(char *str);
char *str_concat(char *s1, char *s2);
char *_strstr(char *haystack, char *needle);
char *counter_to_string(int i, char *to_string);
char *search_path(list_t *head, char *c, char *av, char **to_string);

list_t *add_node_end(list_t **head, char *str);




#endif /* SHELL_H */
