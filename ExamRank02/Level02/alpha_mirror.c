#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int count = 0;

    if (argc == 2)
        {
            while (argv[1][i])
                {
                    if (argv[1][i] >= 66 && argv[1][i] <= 77)
                        {
                            count = argv[1][i] -64;
                            argv[1][i] += 27 - (count*2);
                        }
                    else if (argv[1][i] >= 78 && argv[1][i] <= 89)
                        {
                            count = argv[1][i] -78;
                            argv[1][i] -= count*2+1;
                        }
                    else if (argv[1][i] == 97 || argv[1][i] == 65)
                        argv[1][i] += 25;
                    else if (argv[1][i] == 122 || argv[1][i] == 90)
                        argv[1][i] -= 25;
                    else if (argv[1][i] >= 98 && argv[1][i] <= 109)
                        {
                            count = argv[1][i] -96;
                            argv[1][i] += 27 - (count*2);
                        }
                    else if (argv[1][i] >= 110 && argv[1][i] <= 121)
                        {
                            count = argv[1][i] -110;
                            argv[1][i] -= count*2+1;
                        }
                    write (1, &argv[1][i], 1);
                    i++;
                    count = 0;
                }
        }
        write (1, "\n", 1);
}