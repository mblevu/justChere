#include "shell.h"

/**
 * get_line - read a line of input from stdin
 * @void: no arguments passed
 * Return: return the string containing line of input
 */

char *get_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t linelen = getline(&line, &bufsize, stdin);

	if (linelen == -1)
	{
		perror("getline");
		exit(EXIT_FAILURE);
	}
	/*remove trailing ewline character*/
	if (line[linelen - 1] == '\n')
	{
		line[linelen - 1] = '\0';
	}
	return (line);
}
