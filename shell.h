#ifndef _SHELL_H_
#define _SHELL_H_

#define BUFSIZE 1024
#define ARGV_MAX 100
#define READ_BUF_SIZE 1024
extern char **environ;


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <stddef.h>
#include <errno.h>
#include <stdbool.h>

/* builtin.c */
int _builtin(char *buff, char **argv);
int _ex_builtin(char **argv);
void _cleanup_memory(char *buff, char **argv);

/* getline.c */
int _getline_helper(char **ptr, size_t *buff_size);
ssize_t _getline(char **ptr, size_t *buff_size, FILE *stream);
char *_memset(char *p, char b, unsigned int n);
void ffree(char **ss);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* strtok1.c */
char *_strtok(char *str, const char *delimiter);

/* fork.c */
int c_execute(char **av, char *path, char **argv, char **env);

/* string_fun.c */
char *_strcpy(char *d, const char *s);
size_t _strlen(const char *st);
char *my_strcat(char *dest, const char *src);
char *my_strdup(const char *str);
int _strcmp(const char *str1, const char *str2);

/* string_fun2.c */
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strdup(const char *str);

/* error.c */
void error_note(char *av, int i, char *argv);
void free_argv(char **argv);

/* parse.c */
void parser(char *buff, char **argv, const char *delimiter);

/* getlocation.c */
char *_getenv(const char *name);
char *_strchr(const char *str, int c);
void _env(void);

/* path.c */
char *get_location(const char *argv, const char *av);
char *path_place(const char *path, const char *argv, const char *av);

/* loop.c */

/* main.c */
int  main(int c, char **av, char **env);

#endif
