#include "shell.h"

int main(void)
{
	char **argv;
	char *prompt = "myshell$ ";
	char *command = NULL, *commandcpy = NULL;
	ssize_t cmdread;
	size_t n = 0;
	int numtokens = 0;
	char *token;
	const char *delim = "\n";
	int incr;

	while (1)
	{
		printf("%s", prompt);
		fflush(stdout);
		cmdread = my_getline(&command, &n, stdin);

		/* EOF Handling */
		if (cmdread == -1)
		{
			printf("Exiting myshell.......\n");
			return (-1);
		}

		commandcpy = malloc(sizeof(char) * cmdread);
		if (commandcpy == NULL)
		{
			perror("memory allocation failed");
			return (-1);
		}
		strcpy(commandcpy, command);

		token = my_strtok(command, delim);
		while (token != NULL)
		{
			numtokens++;
			token = my_strtok(NULL, delim);
		}
		numtokens++;

		argv = malloc(sizeof(char *) * numtokens);
		token = my_strtok(commandcpy, delim);
		
		for (; token != NULL; incr++)
		{
			argv[incr] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[incr], token);
			token = my_strtok(NULL, delim);
		}
		argv[incr] = NULL;

	}
	free(commandcpy);
	free(command);

	return (0);
}
