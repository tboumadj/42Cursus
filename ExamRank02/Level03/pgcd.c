#include <stdio.h>
#include <stdlib.h>

void pgcd(unsigned int nb1, unsigned int nb2)
{
    unsigned int div = 1;
    unsigned int result;
    if ( nb1 <= 0 || nb2 <= 0)
        return ;
    while ( div <= nb1 || div <= nb2)
    {
        if (nb1 % div == 0 && nb2 % div == 0)
            result = div;
        div++;
    }
    printf("%d", result);
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        pgcd(atoi(argv[1]),atoi(argv[2]));
    }
        printf("\n");
        return (0);
}