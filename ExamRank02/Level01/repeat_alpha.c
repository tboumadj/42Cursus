#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int nb = 0;

    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] > 64 && argv[1][i] < 91)
                nb = argv[1][i] -64;
            else if (argv[1][i] > 96 && argv[1][i] < 123)
                nb = argv[1][i] -96;
            else
                write (1, &argv[1][i], 1);

            while (nb)
            {
                write (1, &argv[1][i], 1);
                nb--;
            }
            nb = 0;
            i++;
        }
        write (1, "\n", 1);
    }
    write (1, "\n", 1);
}