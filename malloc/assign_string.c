#include <stdio.h>
#include <stdlib.h>

/**
 * assign memory of 3bytes to a string 
 * 
*/
int main(void)
{
    char *str;

    str = malloc(sizeof(char) * 3);
    str[0] = 'O';
    str[1] = 'K';
    str[2] = '\0';
    
    printf("Assigned string: %s\n", str);
    free(str);
    return (0);
}