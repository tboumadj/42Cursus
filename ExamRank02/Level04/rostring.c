#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int count(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i])
    {
        if (str[i] > 32 && str[i+1] <= 32 || str[i] > 32 && str[i+1] == '\0')
            count++;
        i++;
    }
    return (count);
}

int wordsize(char *str)
{
    int i = 0;
    int l = 0;
    while (str[i])
    {
        if (str[i] > 32)
            l++;
        i++;
    }
    return (l);
}

int firstword(char *str)
{
    int j = 0;
    while (str[j] <= 32)
        j++;
    while (str[j] > 32 && str[j+1] > 32)
        j++;
    j++;
    return (j);
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    int r = 0;
    int t = 0;
    char *final;

    if (argc == 2)
    {
        int c = count(argv[1]);
        int l = wordsize(argv[1]);
        final = malloc(sizeof(char) * (c + l)+1);
        if (!final)
            return (0);
        if (c == 1)
            {
                while (argv[1][t] <= 32)
                    ++t;
                while (argv[1][t] > 32)
                    final[i++] = argv[1][t++];
                final[i] = '\0';
                t = 0;
                write (1, &final[t], i);
                write (1, "\n", 1);
                return (0);
            }
        j = firstword(argv[1]);
        t = j;
        while (argv[1][t] <= 32)
            t++;
        while (argv[1][t])
        {
            if (argv[1][t] > 32)
                final[i++] = argv[1][t++];
            else if (argv[1][t] <= 32 && argv[1][t+1] > 32)
                final[i++] = argv[1][t++];
            else if (argv[1][t] <= 32 && argv[1][t+1] <= 32)
                ++t;
        }
        if (argv[1][t] == '\0')
        {
            final[i++] = 32;
            while (r < j)
            {
                if (argv[1][r] > 32)
                    final[i++] = argv[1][r++];
                else if (argv[1][r] <= 32)
                    r++;
            }
        }
        final[i] = '\0';
        j = 0;
        write (1, &final[j], i);
    }
    write(1, "\n", 1);
    return (0);
}