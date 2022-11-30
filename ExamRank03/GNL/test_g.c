#include "gnl.h"

size_t  ft_strlen(const char *str)
{
    int i = 0;

    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

char    *ft_strchr(const char *str, int c)
{
    unsigned int i = 0;

    if (!str)
        return (NULL);
    while ((str[i]) && (str[i] != c))
        i++;
    if (str[i] == c)
        return ((char *)&str[i]);
    return (NULL);
}

char    *strjoin(char *s1, char *s2)
{
    char    *tmp;
    int     i = 0;
    int     j = 0;

    if (!s1)
    {
        s1 = (char *)malloc(sizeof(char) * 1);
        s1[0] = '\0';
    }
    tmp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!tmp)
        return (NULL);
    while (s1[j])
        tmp[i++] = s1[j++];
    j = 0;
    while (s2[j])
        tmp[i++] = s2[j++];
    tmp = '\0';
    free (s1);
    return (tmp);
}

char    *get_next_line(int fd)
{
    static char *str;
    char        *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    str = ft_read(str, fd);
    if (!str)
    return (NULL);
    line = ft_line(str);
    str = ft_save(str);
    return (line);
}

int main(char **argv, int argc)
{
    int fd;
    char *tmp;
    int i = 0;

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("ERROR FD\n");
        return (0);
    }
    while (1)
    {
        tmp = get_next_line(fd);
        if (tmp == NULL)
        {
            free (tmp);
            break ;
        }
        printf("%s\n", tmp);
        free(tmp);
    }
}