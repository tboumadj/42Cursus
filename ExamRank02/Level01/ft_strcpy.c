#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
 
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    printf("%s", s1);
    return (s1);
}

int main()
{
char a[] = "bonjour";
char b[] = "salut";
ft_strcpy(a, b);
}