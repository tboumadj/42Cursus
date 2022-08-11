#include <unistd.h>

int main (int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int t = 0;
    int count = 0;

    if (argc == 3)
    {
        if (!argv[1])
            write (1, "1", 1);
        while (argv[1][t])
            ++t;
        while (argv[2][j])
            {
                if (argv[1][i] == argv[2][j])
                {
                    count += 1;
                    i++;
                }
                j++;
            }
        if (count == t)
                write (1, "1", 1);
        else
            write (1, "0", 1);
    }
    write (1, "\n", 1);
    return (0);
}