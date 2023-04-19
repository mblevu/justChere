#include "shell.h"

/**
 * unset_env - unset an environmennt variable
 * @args: check the arguments
 * Return: void type
 */

void unset_env(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "unsetenv: Too few arguments.\n");
		return;
	}
	if (unsetenv(args[1]) != 0)
	{
		fprintf(stderr, "unsetenv: %s\n", strerror(errno));
	}
}
