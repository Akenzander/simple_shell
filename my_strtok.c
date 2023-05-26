#include "shell.h"

/**
 * my_strtok - A function that breaks string into tokens
 * @str: Pointer to the string to be tokenized
 * @delim: Pointer to the delimeters in the string
 *
 * Return: Token from the string
 */

char *my_strtok(char *str, const char *delim)
{
	char *last_token = NULL; /*remembers the last token*/
	char *token = NULL;

	/*If str is NULL, start with the last token found*/
	if (str == NULL)
	{
		str = last_token;
	}

	/*Find the start of the next token*/
	str += strspn(str, delim);

	/*If the string is empty or contains only delimiters, return NULL*/

	if (*str == '\0')
	{
		return (NULL);
	}

	/*Find the end of the next token*/
	token = str;
	str = strpbrk(token, delim);

	if (str != NULL)
	{
		*str = '\0';
		last_token = str + 1;
	}
	else
	{
		last_token = (NULL);
	}

	return (token);
}
