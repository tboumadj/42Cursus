#include <string.h>
#include <stdio.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j = 0;
    while (s[i])
    {
        j = 0;
            while (reject[j] != '\0' && reject[j] != s[i])
                j++;
            if (s[i] == reject[j])
                return (i);
            i++;
    }
    return (i);
}

int main()
{
    char a[] = "bonjour";
    char b[] = "adcr";
    printf("%lu\n", ft_strcspn(a, b));
    printf("%lu\n", strcspn(a, b));
}
