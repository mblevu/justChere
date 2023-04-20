#include "shell.h"

/**
 * my_strtok - strtok() implementation
 * @str: pointer to the psth
 * @delim: pointer to the delimiitng character
 * Return: each directory path
*/
char *my_strtok(char *str, const char *delim)
{
	char *last = NULL;
	char *tok, *p;

	if (str != NULL)
	{
		last = str;
	}
	else if (last == NULL)
	{
		return (NULL);
	}
	tok = last;
	p = my_strpbrk(tok, delim);

	if (p != NULL)
	{
		*p = '\0';
		last = p + 1;
	}
	else
	{
		last = NULL;
	}

	return (tok);
}
