#include <unistd.h>

#include <unistd.h>

int main (int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int t = 0;
    if (argc == 2)
    {
        while (argv[1][j] != '\0')
            j++;
        i = j;
        while (i >= 0)
            {
                while (argv[1][i] <= 32)
                {
                    if (argv[1][i-1] > 32)
                        j = i;
                    i--;
                }
                while (argv[1][i] > 32)
                    {
                        if (argv[1][i] > 32 && argv[1][i-1] <= 32)
                            {
                                t = j - i;
                                write(1, &argv[1][i], t);
                              if (i > 0)
                                write(1, " ", 1);
                                j = i;
                                
                            }
                        i--;
                    }
            }
    }
}