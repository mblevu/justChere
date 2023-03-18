#include <stdio.h>
#include <stddef.h>

/**
 *  
 * check string for same elements in both
*/

char *_strpbrk(char *s, char *accept)
{
    char *p1, *p2;

    for (p1 = s; * p1 != '\0'; p1++)
    {
        for (p2 = accept; * p2 != '\0'; p2++)
        {
            if (* p1 == * p2)
            {
                return (p1);
            }
        }
    }
    return (NULL);
      
}

int main(void)
{
    char s[]= "hello, world";
    char *t;

    t = _strpbrk(s, "f");
    if (t != NULL)
    {
        printf("found at position %ld\n", t - s);
    }
    else 
    {
        printf("Not found!\n");
    }
    
    return (0);
}