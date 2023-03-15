#include <stdio.h>
#include <stdlib.h>
/**
 * multiply 2 integers
 * error if 2 integers not found
*/
int main(int argc,char *argv[])
{ 
    if (argc != 3)
    {
        printf("Error!!!\n");
        return 1;
    }

    int num1 = atoi(argv[1]);
    int num2 = atoi(argv[2]);

    int result;
    result = num1 * num2;

    printf("%d * %d = %d\n", num1, num2, result);
    return 0;
}

