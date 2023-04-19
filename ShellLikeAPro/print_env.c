#include "shell.h"

/**
 * print_env - print environment
 * @envp: double pointer to environment path
 * Return: return void type
 */

void print_env(char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		printf("%s\n", envp[i]);
	}
}
