#include <stdio.h>

/**
 * take two numbers
 * choose operator
 * return result
*/
int main()
{
    char op;
    float num1, num2, result;

    printf("choose operand(+, -, *, /): \n");
    scanf("%c", &op);

    printf("input 2 numbers: ");
    scanf("%f %f", &num1, &num2);
    switch (op)
    {
        case '+':
        result = num1 + num2;
        break;

        case '-':
        result = num1 - num2;
        break;

        case '*':
        result = num1 * num2;
        break;

        case '/':
        if (num2 == 0)
        {
            printf("Error!!!Division by zero not allowed\n");
        }
        else 
        {
            result = num1 / num2;
        }

        default:
        printf("Invalid operation\n");
        return (1);

    }
    printf("result: %f\n", result);

    return (0);


}