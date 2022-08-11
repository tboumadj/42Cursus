#include <stdio.h>

int check_base(const char c, int str_base)
{
    int i = 0;
    char base1[] = "0123456789abcdef";
    char base2[] = "0123456789ABCDEF";

    while (i < str_base)
    {
        if (c == base1[i] || c == base2[i])
            return (i);
        i++;
    }
    return (-1);
}

int	ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int nb = 0;
    int neg = 0;
    if (str[0] == 45)
        {
            neg = 1;
            i++;
        }
    while (str[i] <=32)
        i++;
    while (check_base(str[i], str_base) != -1)
    {
        nb = nb * str_base ;
        nb = nb + check_base(str[i], str_base);
        i++; 
    }
    if (neg == 1)
        return (-nb);
    return (nb);
}

int main()
{
    char a[] = "123dfb3yz";
    int b = 10;
    printf("%d", ft_atoi_base(a, b));
}