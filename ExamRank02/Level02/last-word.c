#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    char *word;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] <= 32 && argv[1][i+1] > 32)
                word = &argv[1][i+1];
            i++;
        }
        i = 0;
        while (word[i] && word[i] > 32)
        {
            write (1, &word[i], 1);
            i++;
        }
    }
}
