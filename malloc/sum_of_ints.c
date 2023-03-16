#include <stdio.h>
#include <stdlib.h>

void sum_of_ints(int n1, int n2, int n3)
{
    int *t;
    int sum;

    t = malloc(sizeof(*t) * 3);
    t[0] = n1;
    t[1] = n2;
    t[2] = n3;

    sum = t[0] + t[1] + t[2];
    printf("%d + %d + %d = %d\n", n1, n2, n3, sum);

}

/**
 * entry point - call the function
*/
int main(void)
{
    sum_of_ints(98, 402, -1024);
    return(0);
}