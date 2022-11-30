/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exam_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tboumadj <tboumadj@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:57:55 by sloghmar          #+#    #+#             */
/*   Updated: 2022/11/30 16:26:47 by tboumadj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

void	put_str(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		*len += write(1, str++, 1);
}

void	put_digit(long long int nbr, int base, int *len)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (nbr < 0)
	{
		nbr *= -1;
		*len += write(1, "-", 1);
	}
	if (nbr >= base)
		put_digit((nbr / base), base, len);
	*len += write(1, &hexa[nbr % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int			len;
	va_list		ptr;

	len = 0;
	va_start(ptr, format);
	while (*format)
	{
		if ((*format == '%') && *(format + 1))
		{
			format++;
			if (*format == 's')
				put_str(va_arg(ptr, char *), &len);
			else if (*format == 'd')
				put_digit((long long int)va_arg(ptr, int), 10, &len);
			else if (*format == 'x')
				put_digit((long long int)va_arg(ptr, unsigned int), 16, &len);
		}
		else
			len += write(1, format, 1);
		format++;
	}
	va_end (ptr);
	return (len);
}

/*int main()

{
	printf("%x\n", 1566545);
	ft_printf("%x", 1566545);

	return (0);
}*/

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

