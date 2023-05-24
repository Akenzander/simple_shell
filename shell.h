#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;
ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char *my_strtok(char *str, const char *delim);
void *my_realloc(void *ptr, size_t size);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);
unsigned int _strspn(char *s, char *accept);
char *_strpbrk(char *s, char *accept);
#endif
