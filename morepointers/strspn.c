#include <stdio.h>

/**
 * get length of prefix substring
 * 
*/

unsigned int _strspn(char *s, char *accept)
{
    int i, j;
    
    for (i = 0; s[i]; i++)
    {
        for (j = 0; accept[j]; j++)
        {
            if (s[i] == accept[j])
            {
                break;
            }        
        }
        if (!accept[j])
        {
            return (i);
        }
    }
    return (i);
}

int main(void)
{
    char *s = "hello world";
    char *f = "oleh";

    unsigned int n;

    n = _strspn(s, f);
    printf("%u\n", n);
    return (0);
}