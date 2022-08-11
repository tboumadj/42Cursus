#include <stdio.h>

int		max(int* tab, unsigned int len)
{
    int i = 0;
    int tmp;

    if(!tab)
        return (0);
    tmp = tab[0];
    while (i <= len)
        {
            if (tmp < tab[i])
                tmp = tab[i];
            i++;
        }
    return (tmp);
}

int main()
{
    int a[] = {1,2,3,4,5,9,8};
    unsigned int b = 7;
    max(a, b);
}