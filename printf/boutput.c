#include <stdarg.h>
#include <stdio.h>

int _putchar(char c)
{
    return (putchar(c));
}

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    const char *p = format;

    va_start(args, format);

    while (*p != '\0')
    {
        if (*p== '%')
        {
            switch (*(++p))
            {
                case 'c':
                _putchar(va_arg(args, int));
                count++;
                break;

                case 's':
                count += printf("%s", va_arg(args, char *));
                break;

                case 'd':
                case 'i':
                count += printf("%d", va_arg(args, int));
                break;

                case 'b':
                {
                    unsigned int val= va_arg(args, unsigned int);
                    int i;
                    for (i = 31; i >= 0; i--)
                    {
                        int bit = (val >> i) & 1;
                        count += _putchar('0' + bit);
                    }
                    break;

                }
                case '%':
                _putchar('%');
                count++;
                break;

                default:
                _putchar('%');
                _putchar(*p);
                count += 2;
                break;        
        }
    }
    else 
    {
        _putchar(*p);
        count++;
    }
    p++;
}

va_end(args);

return(count);
}


int main(void)
{
	_printf("%b\n", 98);
	return (0);
}

