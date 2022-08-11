#include <stdio.h>

int	ft_atoi(const char *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;

    while (str[i] <= 32)
    i++;
    if (str[i] == 45)
    {
        neg *= -1;
        i++;
    }
    while (str[i] != '\0' && str[i] >= 48 && str[i] <= 57)
    {
        nb *= 10;
        nb += str[i] - 48;
        i++;
    }
    return (nb * neg);
}

int main()
{
    char a[] = "   1234abcd";
    printf("%d\n", ft_atoi(a));
}