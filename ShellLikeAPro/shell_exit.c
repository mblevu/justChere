#include "shell.h"

/**
 * shell_exit - exit the shell
 * @args: double pointer to args to check second element
 * Return: void
 */
void shell_exit(char **args)
{
	int status;

	if (args[1] != NULL)
	{
		status = atoi(args[1]);
		exit(status);
	}
	else
	{
		exit(EXIT_SUCCESS);
	}
}
