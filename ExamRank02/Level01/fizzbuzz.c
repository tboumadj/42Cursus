#include <unistd.h>

void    putchar(char c)
{
    write(1, &c, 1);
}

void    putnbr(int nb)
{
    if (nb < 10)
        putchar(nb + 48);
    else
    {
        putnbr(nb / 10);
        putnbr(nb % 10);
    }
}

int main()
{
    int i = 1;

    while (i <= 100)
    {
        if (i % 3 == 0)
        {
            write (1, "fizz", 4);
        }
        if (i % 5 == 0)
        {
            write (1, "buzz", 4);
        }
        if (i % 3 != 0 && i % 5 != 0)
            putnbr(i);
        i++;
        write (1, "\n", 1);
    }
}