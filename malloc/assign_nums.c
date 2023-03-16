#include <stdio.h>
#include <stdlib.h>

/**
 * allocate memory for 3 integers
*/
int main(void)
{
    int *nums;

    nums = malloc(sizeof(*nums) * 3);
    nums[0] = 98;
    nums[1] = 402;
    nums[2] = -1024;

    printf("%d, %d, %d\n", nums[0], nums[1], nums[2]);
    free(nums);
    return 0; 
}