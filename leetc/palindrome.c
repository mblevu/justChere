#include <stdio.h>
#include <stdbool.h>

/**
 * check palindrome
 * return true if palindrome
*/

bool isPalindrome(int x)
{
    long long y = 0;
    int original = x;

    while (x > 0)
    {
        y = y * 10 + x % 10;
        x /= 10;

    }
    return (y == original);

}

int main(void)
{
    int test_cases[] = {121, 1221, 12321, 12345, -121, 10, 0};
    int num_cases = sizeof(test_cases) /sizeof(int);
    int i;

    for (i = 0; i < num_cases; i++)
    {
        int num= test_cases[i];
        printf("test case %d: ", i + 1);

        if (isPalindrome(num))
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }
    return (0);
}