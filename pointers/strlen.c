#include <stdio.h>

int _strlen(char *s)
{
    int count;
    for (count = 0; *s != '\0'; s++)
    {
        count++;
    }
    return count;
}

int main(void)
{
    char *str;
    int len;
    
    str = "this is a string";
    len = _strlen(str);
    printf("%d\n", len);
    return (0);
}