#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

void	ft_put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	ft_put_nbr(long long int nbr, int base, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		*len += write (1, "-", 1);
	}
	if (nbr >= base)
		ft_put_nbr((nbr /base), base, len);
	*len += write (1, &hexa[nbr % base], 1);
}

int ft_printf(const char *format, ...)
{
    int		len;
	va_list	arg;

	len = 0;
	va_start(arg, format);
	while (*format)
	{
		if ((*format == '%') && (*format + 1))
		{
			format++;
			if (*format == 's')
				ft_put_str(va_arg(arg, char *), &len);
			else if (*format == 'd')
				ft_put_nbr((long long int)va_arg(arg, int), 10, &len);
			else if (*format == 'x')
				ft_put_nbr((long long int)va_arg(arg, unsigned int), 16, &len);
			else if (*format == '%')
				len += write(1, format, 1);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end (arg);
	return (len);
}

int main()
{
	int i = INT_MIN;
	int j = 777;
	int c;
	int d;
	char a[] = "bonjour";

	printf("%%\n");
	ft_printf("%%\n");
	printf("%d\n", j);
	ft_printf("%d\n", j);
	printf("%s\n", a);
	ft_printf("%s\n", a);
	c = printf("%x\n", -777);
	printf("%d\n", c);
	d = ft_printf("%x\n", -777);
	printf("%d\n", d);
}