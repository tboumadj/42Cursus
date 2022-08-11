#include <unistd.h>

int    ft_check(char find, const char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == find)
            return (1);
        i++;
    }
    return (0);
}

int ft_double(char let, const char *search, int a)
{
    int i = 0;
    while (i < a)
    {
        if (let == search[i])
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int i = 0;
    if (argc == 3)
    {
        while (argv[1][i] != '\0')
        {
            if (ft_check(argv[1][i], argv[2]) == 1)
            {
                if (ft_double(argv[1][i], argv[1], i))
                    write (1, &argv[1][i], 1);
            } 
            i++;
        }
    }
    write (1, "\n", 1);
}
