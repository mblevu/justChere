#include <stdio.h>

/**
 * @p: contains address of n -- value of n set to p
 * @pp: contains address of p --value of p set to pp
 * @*p: points to address of n
 * @**pp: points to address of p --returns value of n
*/
int main(void)
{
    int **pp;
    int *p;
    int n = 17;

    p = &n;
    pp = &p;

    printf("pp = %d\n", **pp);

    return (0);
}