#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * array of integers
 * indexing elements of arrays
*/
int main(void)
{
    int numbers[] = {1,2,3,4,5};

    numbers[5] = 6;

    for (int i = 0; i < 6; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    printf("third number is: %d\n", numbers[2]);

    return (0);

}