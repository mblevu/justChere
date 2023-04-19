#include "shell.h"

/**
 * exit_status - checks whether user has provided an exit status
 * @args: pointer to the arguments
 * Return: void type
 */

void exit_status(char **args)
{
	int status = 0;

	if (args[1])
	{
		status = atoi(args[1]);
	}
	exit(status);
}
