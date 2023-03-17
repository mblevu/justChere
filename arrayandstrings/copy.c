#include <stdio.h>
#include <stdlib.h>

/**
 * copy element to another array
*/

int main(void)
{
    int nums1[5] = {1,2,3,4,5};
    int nums2[5];

    for (int i = 0; i < 5;i++)
    {
        nums2[i] = nums1[i];
    }

    printf("***The first array (nums1) contains****\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", nums1[i]);
    }
    printf("\n");

    printf("****The second array (nums2) contains****\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", nums2[i]);
    }
    printf("\n");

    return (0);
}