#include <unistd.h>

void ft_putchar(char c)
{
    write (1, &c, 1);
}

void ft_capitalizer(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if ((str[i] >= 65 && str[i] <= 90) && str[i-1] > 32)
            ft_putchar(str[i] + 32);
        else if ((str[i] >= 97 && str[i] <= 122) && str[i-1] <= 32)
            ft_putchar(str[i] - 32);
        else
            ft_putchar(str[i]);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    if (argc > 1)
    {
        while (i < argc)
        {
            ft_capitalizer(argv[i]);
            write (1, "\n", 1);
            i++;
        }
    }
    else
        write(1, "\n", 1);
    return (0);
}