#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}

void ft_putnbr(int nb)
{
    if (nb < 10)
        ft_putchar(nb +48);
    else
    {
        ft_putnbr(nb / 10);
        ft_putnbr(nb % 10);
    }
}

int ft_atoi(char *str)
{
    int i = 0;
    int nb = 0;
    while (str[i] <= 32)
        i++;
    while (str[i] && str[i] > 32)
        {
            nb *= 10;
            nb += str[i] - 48;
            i++;
        }
        return (nb);
}

int main(int argc, char **argv)
{
    int i = 1;
    int nb;
    if (argc == 2)
    {
        nb = ft_atoi(argv[1]);
        while (i <= 9)
        {
            ft_putnbr(i);
            write(1, " x ", 3);
            ft_putnbr(nb);
            write(1, " = ", 3);
            ft_putnbr(i * nb);
            write(1, "\n", 1);
            i++;
        }
    }
    if (argc != 2)
        write (1, "\n", 1);
    return (0);
}