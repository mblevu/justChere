#include <stdio.h>
#include <stdlib.h>

void *create_array(unsigned int size, char c);
/**
 * call create_array function to array
 * check if array is empty
 * iterate through the elements and print each
 * free the array memory
*/
int main(void)
{
    char *arr = create_array(10, 'a');

    if (arr == NULL)
    {
        printf("Failed!!!\n");
        return 1;
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%c ", arr[i]);
    }
    printf("\n");
    free(arr);
    return 0;
    
}
/**
 * check for size of array
 * allocate array memory using malloc
 * check if array is empty
 * iterate through the elements and set them in array
 * 
*/

void *create_array(unsigned int size, char c)
{
    if (size == 0)
    {
        return (NULL);
    }

    char *arr = malloc(size * sizeof(char));

    if (arr == NULL)
    {
        return (0);
    }

    for (int i =0; i < size; i++)
    {
        arr[i] = c;
    }

    return arr;
}