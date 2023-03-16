#include <stdio.h>
#include <stdlib.h>

/**
 * check return value of malloc
*/

int main(void)
{
    char *s;
    int i;

    i = 0;

    while (1)
    {
        s = malloc(__INT_MAX__);
        if (s == NULL)
        {
            printf("cant alocate %d bytes (after %d calls)\n", __INT_MAX__, i);
            return (1);
        }
        s[0] = 'H';
        i++;
    }
    return (0);
}