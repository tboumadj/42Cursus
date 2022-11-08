/*    main  uni <std + stdlib>

static STR + char TMP
return TMP
SAVE apres \n dans STR

Read le tout et save dans STR

Save de str a TMP toiut ce kil y a juska \n

separer avant \n et garder le reste dans STR 

ft_strchr -> remonte la chaine juska trouver C et renvoi depuis ce pointeur

ft_strlen -> parcours la chaine et renvoi index total

ft_strjoin -> creer un malloc de s1 + s2 met dabord s1 puis s2
*/

#include "gnl.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (0);
	while ((str[i] != '\0') && (str[i] != c))
		i++;
	if (str[i] == c)
		return ((char *)&str[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*tmp;
	int		i;
	int		j;

	if(!s1)
	{
		s1 = (char*)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	i = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if(!tmp)
		return (NULL);
	while (s1[i] != '\0')
		tmp[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		tmp[j++] = s2[i++];
	tmp[j] = '\0';
	free (s1);
	return (tmp);		
}

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
	char *tmp =(char *)malloc(sizeof(char) * (i + 3));
	if (!tmp)
		return (NULL);
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	retun (tmp);
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
			tmp[j++]; = str[i++];
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
	str = read(str, fd);
	if (!str)
		return (NULL);
	tmp = ft_line(str);
	str = ft_save(str);
	return (tmp);
}