#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int fd;

int error(char *string)
{
    while (*string)
        write(2, string++, 1);
    return (1);
}

int cdir(char **argv, int i)
{
    if ( i != 2)
        return error("error cd: bad arguments\n");
    if (chdir(argv[1]))
        return error("error: cd : cannot change directory to ") & error(argv[1]) & error("\n");
    return (0);
}