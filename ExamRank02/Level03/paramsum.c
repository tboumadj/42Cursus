#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c,1);
}

void    putnbr(int nb)
{
    if (nb > 9)
    {
        putnbr(nb / 10);
        putnbr(nb % 10);
    }
    else
        ft_putchar(nb + 48);
}

int main(int argc, char **argv)
{
    int i = argc - 1;
    putnbr(i);
    return (0);
}