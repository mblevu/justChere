#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    while (1)
    {
        malloc(sizeof(char) * 1024);
    }
    return (0);
}