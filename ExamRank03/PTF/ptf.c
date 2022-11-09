#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

int	ft_putchar (int c)
{
	write (1, &c, 1);
	return (1);
}

int	intlen_x(unsigned int nb)
{
	int len = 0;

	if (nb == 0)
		len++;
	while (nb)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	strint(int nb, int base)
{
	int	len = 0;
	int	neg;
	int numb;

	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		neg = 1;
		numb = -nb;
	}
	else
	{
		neg = 0;
		numb = nb;
	}
	while (numb)
	{
		numb /= base;
		len ++;
	}
	return (len + neg);
}

int	ft_pourcents(char *s)
{
	int	i = 0;

	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while(s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

int	putnbr_d(long long int nb)
{
	long long int	c = nb;
	int len = 0;

	if (c < 0)
	{
		ft_putchar('-');
		c = c * -1;
	}
	if (c < 10)
		ft_putchar(c + 48);
	else
	{
		putnbr_d(c / 10);
		putnbr_d(c % 10);
	}
	len += strint(nb, 10);
	return (len);
}

int putnbr_x(unsigned int nb)
{
	int	len = 0;

	if (nb >= 16)
	{
		putnbr_x(nb / 16);
		putnbr_x(nb % 16);
	}
	else
	{
		if (nb <= 9)
			ft_putchar(nb + '0');
		else
			ft_putchar(nb - 10 + 'a');
	}
	len += intlen_x(nb);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i = 0;
	int		len = 0;

	va_start(arg, format);
	while (format[i])
	{
		if (format[i] == '%')
			{
				i++;
				if (format[i] == 's')
					len += ft_pourcents(va_arg(arg, char *));
				if (format[i] == 'd')
					len += putnbr_d((long long int)(va_arg(arg, int)));
				if (format[i] == 'x')
					len += putnbr_x((va_arg(arg, unsigned int)));
			}
		else
			len += ft_putchar(format[i]);
		i++;
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

	printf("%d\n", i);
	ft_printf("%d\n", i);
	printf("%d\n", j);
	ft_printf("%d\n", j);
	printf("%s\n", a);
	ft_printf("%s\n", a);
	c = printf("%x\n", -77777);
	printf("%d\n", c);
	d = ft_printf("%x\n", -77777);
	printf("%d\n", d);
}