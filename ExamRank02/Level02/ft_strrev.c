#include <stdio.h>

char    *ft_strrev(char *str)
{
    int i = 0;
    int j = 0;
    char a;

    while (str[j])
        j++;
    while (i < j)
    {
        a = str[--j];
        str[j] = str[i];
        str[i] = a;
        i++;
    }
    return(str);
}

int main()
{
    char b[] = "!dlrow ,olleh";
    printf("%s\n", ft_strrev(b));
}