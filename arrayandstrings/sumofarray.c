#include <stdio.h>
#include <stdlib.h>

/**
 * prompt the use to enter array of integers
 * get the sum of elements in array
*/

int main(void)
{
    int nums[5] = {1,2,3,4,5};
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
       sum  += nums[i];
    }
    printf("sum:  %d\n",sum);


    return (0);
}