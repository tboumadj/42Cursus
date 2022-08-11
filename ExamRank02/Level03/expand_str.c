#include <unistd.h>

int i = 0;
int main(int argc, char **argv)
{
    if (argc == 2)
    {
        while (argv[1][i] <= 32)
                    i++;
        while (argv[1][i] != '\0')
        {
            if (argv[1][i] <= 32 && argv[1][i+1] > 32)
            {
                write (1, &argv[1][i], 1);
                write (1, &argv[1][i], 1);
                write (1, &argv[1][i], 1);
            }
            if (argv[1][i] > 32)
                    write (1, &argv[1][i], 1);
            i++;
        }
    }
    write (1, "\n", 1);
    return (0);
}