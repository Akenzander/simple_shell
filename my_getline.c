#include "shell.h"

/**
 * my_getline - A function that accepts a string from the input stream as input
 * @lineptr: A double pointer to the buffer where the line will be stored
 * @n: A pointer to the size of the buffer pointed to by lineptr
 * @stream: A pointer to the input file stream from which the line will be read
 *
 * Return: The line read or -1 if an error occurs
 */

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t inptread = 0;
	size_t incr = 0;
	char *new_ptr = NULL;
	void *c = (void *)new_ptr;

	if (*lineptr == NULL)
	{
		*n = 128; /*initial buffer size*/
		*lineptr = malloc(*n);
		if (*lineptr == NULL)
		{
			perror("Unable to allocate memory");
			return (-1);
		}
	}

	while (1)
	{
		int inpt = fgetc(stream);

		if (inpt == EOF || inpt == '\n')
		{
			(*lineptr)[incr] = '\0'; /*terminate the string*/
			break;
		}
		(*lineptr)[incr] = inpt;
		incr++;
		if (incr >= *n)
		{
			*n += 128; /*increase the buffer size*/
			c = my_realloc(*lineptr, *n);
			if (c == NULL)
			{
				perror("Unable to allocate memory");
				return (-1);
			}
			*lineptr = new_ptr;
		}
	}
	if (incr == 0 && inptread == EOF)
	{
		perror("No input read");
		return (-1);
	}
	return (incr);
}
