#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x = 0;

    if (x == 0)
    {
        printf("prgram exited with code 0\n");
        exit(0);
    }
    else
    {
        printf("program exited with code 1\n");
        exit (1);
    }
}
