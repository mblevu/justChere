#include "shell.h"

/**
 * my_strpbrk - check character for a match
 * @s: character to check
 * @accept: character compared to s
 * Return: NULL
 */

char *my_strpbrk(const char *s, const char *accept)
{
	while (*s != '\0')
	{
		const char *a = accept;

		while (*a != '\0')
		{
			if (*s == *a)
			{
				return ((char *)s);
			}
			a++;
		}
		s++;
	}
	return (NULL);
}
