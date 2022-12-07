#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

void    ft_putstr(char *str, int *len)
{
    if (!str)
        str = "(null)";
    while (*str)
        *len += write(1, str++, 1);
}

void    ft_putnbr(long long int nbr, int base, int *len)
{
    char hexa[] = "0123456789abcdef";

    if (nbr < 0)
    {
        nbr *= -1;
        *len += write(1, "-", 1);
    }
    if (nbr >= base)
        ft_putnbr((nbr / base), base, len);
    *len += write(1, &hexa[nbr % base], 1);
}

int    ft_printf(const char *format, ...)
{
    int len = 0;
    va_list arg;

    va_start (arg, format);
    while (*format)
    {
        if ((*format == '%') && (*format + 1))
        {
            format++;
            if (*format == 's')
                ft_putstr(va_arg(arg, char *), &len);
            else if (*format == 'd')
                ft_putnbr((long long int)va_arg(arg, int), 10, &len);
            else if (*format == 'x')
                ft_putnbr((long long int)va_arg(arg, unsigned int), 16, &len);
            else if (*format == '%')
                len += write(1 , format, 1);
        }
        else
            len += write(1, format, 1);
        format++;
    }
    va_end(arg);
    return (len);
}

int main()
{
    char a[] = "salut";
    int b;
    int c;
    int d = 777;
    int e = -777;

    //b = printf("%s\n", a);
    //printf("%d\n", b);
    //c = ft_printf("%s\n", a);
   // printf ("%d\n", c);
    b = printf("%x\n", e);
    printf("%d\n", b);
    c = ft_printf("%x\n", e);
    printf("%d\n", c);
}