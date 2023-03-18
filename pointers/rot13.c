#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * encode a string to rot13
*/
char *rot13(char *str)
{
    char *result = malloc(strlen(str) + 1);
    int i;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            result[i] = ((str[i] - 'a') + 13) % 26 + 'a';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            result[i] = ((str[i] - 'A') + 13) % 26 + 'A';
        }
        else 
        {
            result[i] = str[i];
        }
    }
    result[i] = '\0';

    return (result);
}

int main(void)
{
    char s[] = "ROT13 (\"rotate by 13 places\", sometimes hyphenated ROT-13) is a simple letter subsititution cipher.\n";
    char *p;

    p = rot13(s);
    printf("%s", p);
    printf("---------------------------\n");
    printf("%s", s);
    printf("---------------------------\n");
    p = rot13(s);
    printf("%s", p);
    printf("---------------------------\n");
    printf("%s", s);
    return (0);
}