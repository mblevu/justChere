#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * fizzbuzz if i is divisible by 3 and 5
 * fizz if divisible by 3
 * buzz if divisible by 5
 * n = 3
 * output ["1", "2", "Fizz"]
 * free malloc
*/

char **fizzBuzz(int n, int* returnSize)
{
    char **answer = (char**)malloc(sizeof(char *) * n);
    int i;

    for (i = 1; i <= n; i++)
    {
        if (i % 3 == 0 && i % 5 == 0)
        {
            answer[i - 1] = "FizzBuzz";
        }
        else if (i % 3 == 0)
        {
            answer[i - 1] = "Fizz";
        }
        else if (i % 5 == 0)
        {
            answer[i - 1] = "Buzz";
        }
        else 
        {
            answer[i - 1] = (char *)malloc(sizeof(char) * 12);
            sprintf(answer[i - 1], "%d", i);
        }
    }
    *returnSize = n;
    return (answer);
}


int main(void)
{
    int n = 2;
    char **result = fizzBuzz(n, &n);
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%s\n", result[i]);
    }
    return (0);
}