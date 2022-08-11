#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nb)
{
    if (nb > 16)
    {
        ft_putnbr(nb / 16);
        ft_putnbr(nb % 16);
    }
    if (nb < 10)
        ft_putchar(nb + 48);
    else if (nb >= 10 && nb <= 16)
        ft_putchar (nb + 87);
}

int atoi(char *str)
{
    int i = 0;
    int nb = 0;
    if (!str)
        return (0);
    while (str[i] != '\0')
    {
        nb *= 10;
        nb += str[i] - 48;
        i++;
    }
    return (nb);
}

int main(int argc, char **argv)
{
   
    if (argc == 2)
    {
        ft_putnbr(atoi(argv[1]));
    }
    write (1, "\n", 1);
}