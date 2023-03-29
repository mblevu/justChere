#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverseString(char* s, int sSize);

/**
 * reverse string
*/

void reverseString(char* s, int sSize)
{
    int i = 0; 
    int j = sSize - 1;

    while (i < j)
    {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}

int main(void)
{
    
    char s[] = "hello";
    reverseString(s, sizeof(s));
    printf("%s", s);
    return (0);
}