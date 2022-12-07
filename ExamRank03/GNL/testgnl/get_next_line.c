
#include "get_next_line.h"


char 	*ft_read(char *str, int fd)
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
			free (tmp);
			return (NULL);
		}
		tmp[c] = '\0';
		str = ft_strjoin(str, tmp);
		if (ft_strchr(str, '\n'))
		{
			free (tmp);
			return (str);
		}
	}
	free (tmp);
	return (str);
}

char	*ft_line(char *str)
{
	int i = 0;
	char *tmp;

	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	tmp = (char *)malloc(sizeof(char) * (i + 3));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_save(char *str)
{
	int i = 0;
	int j = 0;
	char *tmp;

	while (str[i] != '\n' && str[i] != '\0')
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
	while (str[i] != '\0')
		tmp[j++] = str[i++];
	tmp[j] = '\0';
	free (str);
	return (tmp);
}

char	*get_next_line(int fd)
{
    static char	*str;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = ft_read(str, fd);
	if (!str)
		return (NULL);
	tmp = ft_line(str);
	str = ft_save(str);
	return (tmp);
}
