#include "shell.h"

/**
 * my_atoi - convert string to integer
 * @str: string to convert
 * Return: resulting interger
 */

int my_atoi(const char *str)
{
	int result, i = 0;
	int sign = 1;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '0')
		{
			return (-1);
		}
		result - result * 10 + (str[i] - '0');
	}
	return (sign * result);
}
