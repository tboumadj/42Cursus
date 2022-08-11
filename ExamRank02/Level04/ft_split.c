#include <stdlib.h>
#include <stdio.h>

int count(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        if (str[i] <= 32 && str[i-1] > 32)
                count++;
        ++i;
    }
    count++;
    return (count);
}

char    *word(char *str)
{
    char *size;
    int i = 0;
    while (str[i] > 32)
        i++;
    size = malloc(sizeof(char) * (i + 1));
    if (!size)
        return (NULL);
    i = 0;
    while (str[i] && str[i] > 32)
    {
        size[i] = str[i];
        ++i;
    }
    size[i] = '\0';
    return (size);
}

char    **ft_split(char *str)
{
    int i = 0;
    int size = count(str);
    char **tab;
    tab = malloc(sizeof(char*) * size + 1);
    if (!tab)
        return (NULL);
    while (*str)
        {
            while (*str <= 32)
                str++;
            if (*str > 32)
                {
                    tab[i] = word(str);
                    ++i;
                    while (*str > 32)
                        str++;
                }
        }
    return (tab);
}

int main()
{
char a[] = "bonjour les amis vous allez bien";
ft_split(a);
}