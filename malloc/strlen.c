#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "Best School";
    int len;

    len = strlen(s);

    printf("%d\n", len);
    printf("%d\n", sizeof(s));
    return 0;
}