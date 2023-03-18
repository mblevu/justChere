#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * encode string to 1337
*/
char *leet(char *str)
{
    int i, j;
    char *leet_str = malloc(strlen(str) + 1);

    if (leet_str == NULL)
    {
        return (NULL);
    }
    for (i = 0, j = 0; str[i] != '\0'; i++, j++)
    {
        switch (str[i])
        {
            case 'a':
            case 'A':
            leet_str[j] = '4';
            break;
            case 'e':
            case 'E':
            leet_str[j] = '3';
            break;
            case 'o':
            case 'O':
            leet_str[j] = '0';
            break;
            case 't':
            case 'T':
            leet_str[j] = '7';
            break;
            case 'l':
            case 'L':
            leet_str[j] = '1';
            break;
            default:
            leet_str[j] = str[i];
        }
    }
    leet_str[j] = '\0';
    return (leet_str);
}

int main (void)
{
    char s[] = "Expect the best,prepare for the worst> Capitalize on what comes.\n";
    char *p;

    p = leet(s);
    printf("%s", p);
    printf("%s", s);
    return (0);
}