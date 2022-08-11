#include <unistd.h>

int ft_check(char c, const char *find)
{
    int i = 0;
    while (find[i])
    {
        if (find[i] == c)
            return (0);
        i++;
    }
    return (1);
}

int ft_double(char c, const char *str, int a)
{
    int i = 0;
    while (i < a)
    {
        if (str[i] == c)
            return (0);
        i++;
    }
    return (1);
}

int main    (int argc, char **argv)
{
    int i = 0;
    if (argc == 3)
    {
        while (argv[1][i])
        {
            if (ft_double(argv[1][i], argv[1], i))
                write (1, &argv[1][i], 1);
            i++;
        }
        i = 0;
        while (argv[2][i])
        {
            if (ft_check(argv[2][i], argv[1]))
            {
                if (ft_double(argv[2][i], argv[2], i))
                    write (1, &argv[2][i], 1);
            }
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}