#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/**
 * program that adds positive numbers.
 * Print the result, followed by a new line
 * If no number is passed to the program, print 0, followed by a new line
 * If one of the number contains symbols that are not digits, print Error, followed by a new line, and return 1
 * You can assume that numbers and the addition of all the numbers can be stored in an int
*/
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("0\n");
        return 0;
    }
    int i, j, sum;

    for (i = 1; i < argc; i++)
    {
       for (j = 0; argv[i][j] != '\0'; j++)
       {
        if (!isdigit(argv[i][j]))
        {
            printf("Error!!!\n");
            return 1;
        }
       }
       sum = sum + atoi(argv[i]);
        
    }
    printf("sum: %d\n",sum);
    return 0;

}