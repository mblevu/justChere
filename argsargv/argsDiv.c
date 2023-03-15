#include <stdio.h>
#include <stdlib.h>
/**                                         1          2      3
 * validate only 2 integers as input --- ./a.out      num1    num2
 * take 2 integers                          argv[0] argv[1]  argv[2]
 * 
*/
int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Error!!!\n");
        return 1;
    }
    
    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    if (num2 == 0)
    {
        printf("Error!!!Division by 0 not allowed\n");
    }

    int result =  num1 / num2;

    printf("Answer: %d\n", result);
    return 0;
}