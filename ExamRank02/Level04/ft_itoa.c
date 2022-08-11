#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

int ft_intlen(int nb)
{
    int i = 0;
    int tmp = 0;
    while (nb)
    {
        nb /= 10;
        i++;
    }
    return (i);
}

char    *ft_itoa(int nb)
{
    int i = 0;
    char *str;
    int tmp = 0;
    int len = ft_intlen(nb);
    if (nb < 0)
        len += 1;
    str = malloc(sizeof(char) * len + 1);
    if (!str)
        return (NULL);
    if (nb < 0)
    {
            str[0] = '-';
            nb *= -1;
            i++;
    }
    str[len--] = '\0';
    while (len >= i)
    {
        if ( nb < 0)
        {
            tmp = nb % 10 * (-1);
            nb = nb / 10;
            str[len] = tmp + 48;
            tmp = 0;
        }
        else
        {
            tmp = nb % 10;
            nb = nb / 10;
            str[len] = tmp + 48;
            tmp = 0;
        }
        len--;
    }
    printf("%s\n", str);
    return (str);
}


int main()
{
    int a = INT_MIN;
    ft_itoa(a);
}