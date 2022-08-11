#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
    int i = 0;
    int j = 0;
    int count = end;
    int s = start;
    int *tab;
    while (s != end)
    {
        if (s < end)
        {
            if (end < 0)
                s -= 1;
            else
                s += 1;
        }
        if (s > end)
            s += 1;
        ++j;
    }
    tab = (int *)malloc(sizeof(int) * (j+1));
    if (!tab)
        return (NULL);
    while (i <= j)
    {
        tab[i] = count;
        count -= 1;
        i++;
    }
    tab[i] = '\0';
    i = 0;
    while (i <= j)
    {
    printf("%d\n", tab[i]);
    i++;
    }
    return (tab);
}

int main()
{
    ft_rrange(-1, 3);
}