#include "gnl.h"

int main(int argc, char **argv)
{
    int fd;
    char *tmp;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        printf("ERROR FD\n");

    while (fd != -1)
    {
        tmp = get_next_line(fd);
        printf("%s\n", tmp);
        //free (tmp);
    }
}