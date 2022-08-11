#include <unistd.h>

int ft_strlen(const char *str)
{
    int i = 0;
    while (str[i])
    i++;
    return (i);
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    char *tmp;

    if (argc == 3)
    {
        while (argv[2][j])
        {
            if (argv[1][i] == argv[2][j] && argv[2][j] != '\0')
                i++;
            j++;
        }
        if (argv[1][i] == '\0')
        {
            i = 0;
            tmp = &argv[1][i];
            a += ft_strlen(argv[1]);
            b += ft_strlen(tmp);
            if (a == b)
                write (1, argv[1], a);
        }
    }
    write (1, "\n", 1);
    return (0);
}