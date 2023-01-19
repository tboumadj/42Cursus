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
    if (i != 2)
        return error("error cd: bad arguments\n");
    if (chdir(argv[1]))
        return error("error: cd : cannot change directory to ") & error(argv[1]) & error("\n");
    return (0);
}

int exec(char **argv, char **envp, int i)
{
    int fds[2];
    int res;
    int pip = (argv[i] && !strcmp(argv[i], "|"));

    if (pip && (pipe(fds)))
        return error("error: fatal\n");
    int pid = fork();
    if (!pid)
    {
        argv[i] = 0;
        if (dup2(fd, 0) == -1 | close(fd) == -1 | (pip && (dup2(fds[1], 1) == -1 | close(fds[0]) == -1 | close(fds[1] == -1))))
            return error("error: fatal\n");
        execve(*argv, argv, envp);
        return error("error: cannot execute ") & error(*argv) & error("\n");
    }
    if ((pip && (dup2(fds[0], fd) == -1 | close(fds[0]) == -1 | close(fds[1]) == -1)) | (!pip && dup2(0, fd) == -1) | waitpid(pid, &res, 0) == -1)
       return error("error: fatal\n");
    return WIFEXITED(res) && WEXITSTATUS(res);
}

int main(int argc, char **argv, char **envp)
{
    (void) argc;
    int i = 0;
    int j = 0;

    fd = dup(0);

    while (argv[i] && argv[++i])
    {
        argv = argv + i;
        i = 0;
        while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
            i++;
        if (!strcmp(*argv, "cd"))
            j = cdir(argv, i);
        else if (i)
            j = exec(argv, envp, i);
    }
    return ((dup2(0, fd) == -1) && error("error: fatal\n")) | j;
}