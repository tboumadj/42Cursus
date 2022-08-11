#include <unistd.h>

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 10)
		ft_putchar(nb + 48);
	else 
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
}

int	ft_atoi(char *str)
{
	int i = 0;
	int result;

		while (str[i])
		{
			result *= 10;
			result += str[i] - 48;
			i++;
		}
	return (result);
}

int	find_prime(int nb)
{
	int a = 2;
	while (a < nb)
	{
		if (nb % a == 0)
			return (0);
		a++;
	}
	return (1);
}

int add_prime(int nb)
{
	int i = 2;
	int result = 0;
	if ( nb <= 0)
		return (0);
	while (i <= nb)
	{
		if (find_prime(i))
			result += i;
		i++;
	}
	return (result);
}

int main(int argc, char **argv)
{
    int i;

    if (argc == 2)
		ft_putnbr(add_prime(ft_atoi(argv[1])));
    if ( argc != 2)
        write (1, "0", 1);
    write (1, "\n", 1);
    return(0);
}
