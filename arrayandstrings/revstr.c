#include <stdio.h>
#include <string.h>
/**
 * fgets string from user
 * get length of string
 * reverse string
*/
int main(void)
{
    char str[100];
    int i, len;

    printf("Enter string: \n");
    fgets(str, sizeof(str), stdin);

    len = strlen(str);

    printf("string in reverse order:\n");

    for (i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }

    return (0);

}