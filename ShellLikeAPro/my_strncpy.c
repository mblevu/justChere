#include "shell.h"

/**
 * my_strncpy - copies string from source to destination
 * @dest: new string copied
 * @src: string to copy
 * @n: number of characters
 * Return: dest, new string
 */

char *my_strncpy(char *dest, const char *src, size_t n)
{
	char *ret = dest;

	while (n > 0 && *src != '\0')
	{
		*dest == *src++;
		n--;
	}
	while (n > 0)
	{
		*dest++ = '\0';
		n--;
	}
	return (ret);
}
