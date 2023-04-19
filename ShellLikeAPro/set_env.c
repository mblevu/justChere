#include "shell.h"

/**
 * set_env - set environment variable
 * @args: pointer to check arguments
 * Return: void type
 */
void set_env(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "setenv: missing argument\n");
	}
	else if (args[2] == NULL)
	{
		if (setenv(args[1], "", 1) != 0)
		{
			perror("setenv");
		}
	}
	else if (args[3] == NULL)
	{
		if (setenv(args[1], args[2], 1) != 0)
		{
			perror("setenv");
		}
	}
	else
	{
		fprintf(stderr, "setenv: too many arguments\n");
	}
}
