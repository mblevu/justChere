#include "shell.h"

/**
 * my_strncmp - compare first n characters of two strings
 * @s1: pointer to first string
 * @s2: pointer to second string
 * @n: number fo characters
 * Return: 0 on success
 */

int my_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] == '\0')
		{
			return (0);
		}
	}
	return (0);
}
