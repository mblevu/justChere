#include <stdio.h>

/**
 * convert temperature
 * celcius and farenheight
*/
int main(void)
{
    float temp, converted_temp;
    char unit;
    printf("Enter the temperature: ");
    scanf("%f", &temp);
    printf("Enter unit of temperature (C/F): ");
    scanf(" %c", &unit);
    if (unit == 'C' || unit == 'c')
    {
        converted_temp = temp * 9 / 5 + 32;
        printf("%.2fC is equivalent to %.2fF\n", temp, converted_temp);
    }
    else if (unit == 'F' || unit == 'f')
    {
        converted_temp = (temp - 32) * 5 / 9;
        printf("%.2fF is equivalent to %.2fC\n", temp, converted_temp);
    }
    else 
    {
        printf("Invalid unit!\n");
        return (1);
    }
    
    return (0);

}