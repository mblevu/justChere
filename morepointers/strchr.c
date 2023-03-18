#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * check for specific character in string
*/

char *_strchr(char *s, char c)
{
    while (*s != '\0')
    {
        if (*s == c)
        {
            return (s);
        }
        s++;
    }
    if (c == '\0')
    {
        return (s);
    }
    return (NULL);
}

int main(void)
{
    char *s = "hello";
    char *f;

    f = _strchr(s, 'l');

    if (f != NULL)
    {
        printf("%s\n", f);
    }
    return (0);
}