#include "get_next_line.h"

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