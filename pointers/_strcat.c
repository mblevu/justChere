#include <stdio.h>
#include "main.h"

/**
 * find end of the string
 * copy source to end of dest
 * add null byte terminator
*/
char *_strcat(char *dest, char *src)
{
    int i, j;

    i = 0;

    while (dest[i] != '\0')
    {
        i++;
    }

    j = 0;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';

    return (dest);

}

int main(void)
{
    char s1[98] = "hello ";
    char s2[] = "world";
    char *ptr;

    printf("string 1: %s\n", s1);
    printf("string 2: %s\n", s2);
    ptr = _strcat(s1, s2);
    printf("%s", ptr);

    return (0);

}