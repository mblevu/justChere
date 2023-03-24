#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

void int_to_str(int value, char *buffer)
{
    int i = 0;
    int is_negative = 0;
    int len, j;

    if (value < 0)
    {
        is_negative = 1;
        value = -value;
    }

    do{
        buffer[i++] = '0'+ (value % 10);
        value /= 10;
    }while (value > 0);

    if (is_negative)
    {
        buffer[i++]= '.';
    }

    buffer[i] = '\0';

    /** reverse the string */

    len = strlen(buffer);
    for (j = 0; j < len/2; j++)
    {
        char tmp = buffer[j];
        buffer[j] = buffer[len -j - 1];
        buffer[len - j - 1] = tmp;
    }
}

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);
    

	int len = strlen(format);
	int num_chars = 0;
    int i;

	for (i = 0; i < len; i++)
	{
		if (format[i] == '%')
		{	
			if (format[i] == 'd' || format[i] == 'i')
			{
				int value = va_arg(args, int);
				char buffer[32];
				int_to_str(value, buffer);
				printf("%s", buffer);
				num_chars += strlen(buffer);
			}
			else 
			{
				putchar('%');
				num_chars++;
			}
		}
		else 
		{
			putchar(format[i]);
			num_chars++;
		}
	}
		va_end(args);

		return (num_chars);	
}


/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");
    return (0);
}