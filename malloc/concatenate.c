#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *str_concat(char *s1, char *s2);

int main(void)
{
    char s1[] =  "hello ";
    char s2[] = "world";
    char *result = str_concat(s1, s2);

    if (result == NULL)
    {
        printf("Failed!!!\n");
        return (1);
    }
    printf("%s\n", result);
    free(result);
    return (0);
}
/**
 * check if the strings are empty
 * get the length of each string and store
 * allocate memory for the result  
*/
char *str_concat(char *s1, char *s2)
{
    if (s1 == NULL) s1 = "";
    if (s2 == NULL) s2 = "";

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    char *result = malloc(len1 + len2 + 1);

    if (result == NULL)
    {
        return (NULL);
    }
    strcpy(result, s1);
    strcat(result, s2);

    return (result);
}