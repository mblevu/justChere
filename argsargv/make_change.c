#include <stdio.h>
#include <stdlib.h>
/**
 * validate only one argument as the coin  ---./a.out num1
 * parse amount of money in argv[1]
 * validate its positive int
 * get minimum amount of coins to make change 
*/
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Error!!!\n");
        return 1;
    }

    int cents = atoi(argv[1]);

    if (cents < 0)
    {
        printf("0\n");
        return 1;
    }

    int num_of_coins = 0;

    num_of_coins += cents/25; cents %= 25;
    num_of_coins += cents/10; cents %= 10;
    num_of_coins += cents/5; cents %= 5;
    num_of_coins += cents/1; cents %= 1;

    printf("%d\n", num_of_coins);

    return 0;

}