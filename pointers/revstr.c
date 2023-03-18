#include <stdio.h>
#include <string.h>
#include "main.h"


void print_reverse(char *str)
{
    int len = strlen(str);
    for (int i = len - 1; i >=0; i--)
    {
        putchar(str[i]);
    }
    putchar('\n');
}

int main(void)
{
    char *str;
    str = "you need to practice alot";
    print_reverse(str);
    return 0;
}