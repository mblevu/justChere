#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * get length of haystack and needle
 * strncmp the substring
*/

char *_strstr(char *haystack, char *needle)
{
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);

    if (needle_len == 0)
    {
        return (haystack);
    }

    for (int i = 0; i <= haystack_len - needle_len; i++)
    {
        if (strncmp(haystack + i, needle, needle_len) == 0)
        {
            return (haystack+ i);
        }
    }
    return (NULL);
}

int main(void)
{
    char *s = "hello, world";
    char *f = "world";
    char *t;

    t = _strstr(s, f);
    printf("%s\n",t);
    return (0);
}

