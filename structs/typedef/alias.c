#include <stdio.h>
#include <string.h>

/**
 * reverse_1337 - reverses strings and encodes
*/

void reverse_1337(char *str)
{
    int i, len = strlen(str);
    char c;
/* reverse string */
    for (i = 0; i < len/2; i++)
    {
        c = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = c;
    }
/* encode to 1337 */
    for (i = 0; i < len; i++)
    {
        switch (str[i])
        {
            case 'a':
            case 'A':
            str[i] = '4';
            break;

            case 'e':
            case 'E':
            str[i] = '3';
            break;

            case 'i':
            case 'I':
            str[i] = '1';
            break;

            case 'o':
            case 'O':
            str[i] = '0';
            break;

            case 's':
            case 'S':
            str[i] = '5';
            break;

            case 't':
            case 'T':
            str[i] = '7';
            break;

            default:
            break;

        }
    }
/* encode to rot13 */
    for (i = 0; i < len; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = (((str[i] - 'a') + 13) % 26) + 'a';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = (((str[i] - 'A') + 13) % 26) + 'A';
        }
    }

}


int main(void)
{
    char str[100];

    printf("Enter a string: ");
    fgets(str, 100, stdin);

    str[strcspn(str, "\n")] = 0;

    reverse_1337(str);

    printf("Reverse and encoded string: %s\n", str);

    return (0);
}

