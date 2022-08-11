#include <stdlib.h>
#include <stdio.h>

char    *ft_strdup(char *src)
{
    int i = 0;
    char *str;
    while (src[i])
        i++;
    str = (malloc(sizeof(char) * (i+1)));
    if (!str)
        return (NULL);
    i = 0;
    while (src[i])
    {
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return (str);   
}

int main()
{
char a[] = "bonjour";
ft_strdup(a);
}