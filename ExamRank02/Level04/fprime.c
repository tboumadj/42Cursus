#include <stdio.h>
#include <stdlib.h>

void    fprime(int nb)
{
    int i = 2;
    if (nb == 1)
        printf("1");
    while (nb >= i)
    {
        if (nb % i == 0)
            {
                printf("%d", i);
                nb /= i;
                if (nb > i)
                    printf("*");
                i--;
            }
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 0;
    if (argc == 2)
    {
        fprime(atoi(argv[1]));
    }
    printf("%c", '\n');
}