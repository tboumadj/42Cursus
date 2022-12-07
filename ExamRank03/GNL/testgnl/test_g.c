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
    tmp[i] = '\0';
    free (s1);
    return (tmp);
}

char    *ft_read(char *str, int fd)
{
    int c = 1;
    char *tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!tmp)
        return (NULL);
    while (c != 0)
    {
        c = read(fd, tmp, BUFFER_SIZE);
        if (c == -1)
        {
            free(tmp);
            return (NULL);
        }
        tmp[c] = '\0';
        str = strjoin(str, tmp);
        if (ft_strchr(str, '\n'))
            {
                free (tmp);
                return (str);
            }
        }
    free (tmp);
    return (str);
}

char    *ft_line(char *str)
{
    int i = 0;
    char    *tmp;

    if (!str[i])
        return(NULL);
    while (str[i] && str[i] != '\n')
        i++;
    tmp = (char *)malloc(sizeof(char) * (i + 3));
    if (!tmp)
        return (NULL);
    i = 0;
    while (str[i] != '\0' && str[i] != '\n')
        {
            tmp[i] = str[i];
            i++;
        }
    if (str[i] == '\n')
        {
            i++;
            tmp[i] = str[i];
            i++;
        }
    tmp[i] = '\0';
    return (tmp);
}

char    *ft_save(char *str)
{
    int     i = 0;
    int     j = 0;
    char    *tmp;

    while (str[i] && str[i] != '\n')
        i++;
    if (!str[i])
        {
            free (str);
            return (NULL);
        }
    tmp = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
    if (!tmp)
        return (NULL);
    i++;
    while (str[i])
        tmp[j++] = str[i++];
    tmp[j] = '\0';
    free (str);
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

int main(int argc, char **argv)
{
    int fd;
    char *tmp;
    int i = 0;
    (void)argc;

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