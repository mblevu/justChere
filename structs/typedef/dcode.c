#include <stdio.h>
#include <string.h>

/**
 * gets the original reversed and encoded string
 * reads encoded string
 * decodes 1337
 * decodes rot13
 * reverses the result
*/
void decode_1337(char *str)
{
    int i, len = strlen(str);
    char c;

    for (i = 0; i < len/2; i++)
    {
        c = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = c;
    }

    for (i = 0; i < len; i++)
    {
        switch (str[i])
        {
            case '4':
            str[i] = 'a';
            break;

            case '3':
            str[i] = 'e';
            break;

            case '1':
            str[i] = 'i';
            break;

            case '0':
            str[i] = 'o';
            break;

            case '5':
            str[i] = 's';
            break;

            case '7':
            str[i] = 't';
            break;

            default:
            break;

        }
    }
}

void decode_rot13(char *str)
{
    int i, len =  strlen(str);

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

    decode_rot13(str);
    decode_1337(str);

    printf("Decoded string: %s\n", str);

    return (0);
}