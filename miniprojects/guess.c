#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * check number, guess and attempts
 * generate random number
 * guess > num: too high ? too low : correct
*/
int main(void)
{
    int number, guess, attempts = 0;
    srand(time(0));
    number = rand() % 100 + 1;
    printf("Enter a number (1-100): \n");
    do {
        scanf("%d", &guess);
        attempts++;

        if (guess > number)
        {
            printf("Too high!\n");
        }
        else if (guess < number)
        {
            printf("Too Low!\n");
        }
        else 
        {
            printf("Correct!\n");
        }
    }while (guess != number && attempts <= 5);

    return (0);

}