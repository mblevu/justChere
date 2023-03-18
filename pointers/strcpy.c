#include "main.h"
#include <stdio.h>

/**
 * set pointer to keep track of destination
 * copy each source character to destination
*/
char *_strcpy(char *dest, const char *src)
{
    char *p = dest;
    while (*src != '\0')
    {
        *p++ = *src++;
    }
    *p = '\0';
    return (dest);
}

int main(void)
{
    char s1[98];
    char *ptr;

    ptr = _strcpy(s1, "copied string\n");
    
    printf("s1: %s", s1);
    printf("new: %s", ptr);

    return (0);
}