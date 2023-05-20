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

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);
char *my_strtok(char *str, const char *delim);
void *my_realloc(void *ptr, size_t size);
#endif
