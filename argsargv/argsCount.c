#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    
    printf("Program name: \n", argv[0]);
    printf("Number of arguments passed: \n", argc - 1);

    for ( i = 1; i < argc; i++)
    {
        printf("Argument %d: %s\n", i, argv[i]);
    }
    return 0;
}