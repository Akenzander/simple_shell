#include "shell.h"

int main()
{
	char *prompt = "myshell$ ";
	char *command;
	size_t n = 0;
	ssize_t cmdread;

	while (1)
	{
		printf("%s", prompt);
		cmdread = my_getline(&command, &n, stdin);

		/* EOF Handling */
		if (cmdread == -1)
		{
			printf("Exiting myshell.......\n");
			return (-1);
		}

		printf("%s\n", command);
		free(command);
	}
	return (0);
}
