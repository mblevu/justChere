#include <stdio.h>
#include <stdlib.h>

/**
 * nums- array of integers
 * target- sum of nums integer target
 * 
*/

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j;
    int *result = (int*)malloc(2 * sizeof(int));
    if (result == NULL)
    {
        return (NULL);
    }
    for (i = 0; i < numsSize; i++)
    {
        for (j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return (result);
            }
        }
    }
    return (NULL);
}

int main(void)
{
    int nums[] = {3, 3};
    int target = 6;
    int returnSize;
    int *result = twoSum(nums, 4, target, &returnSize);

    if (result == NULL)
    {
        printf("No result\n");
    }
    else
    {
        printf("Result: %d, %d\n", result[0], result[1]);
    }

    return (0);
}