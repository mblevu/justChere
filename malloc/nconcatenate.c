#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char *string_nconcat(char *s1, char *s2,unsigned int n);

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    if (s1 == NULL) s1 = "";
    if (s2 == NULL) s2 = "";

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (n >= len2)
        n = len2;

    char *result = malloc(len1 + n + 1);

    if (result == NULL)
    {
        return (NULL);
    }
    strcpy(result, s1);
    strcat(result, s2);
    result[len1 + n] = '\0';
    
    return (result);
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *concat;

    concat = string_nconcat("Best ", "School !!!", 6);
    printf("%s\n", concat);
    free(concat);
    return (0);
}