#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
    int m = 2;
    int result = 2;
    if (n == 1 || n == 2)
        return (1);
    while (result <= n)
        {
            result *= m;
            if (result == n)
                return (1);
        }
    return (0);
}

int main()
{
    int t = 67108866;
    printf("%d\n", is_power_of_2(t));
}