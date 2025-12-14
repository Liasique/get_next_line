#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strdup(const char *s)
{
	size_t	i;
	char	*copy;

	if (!s)
		return (NULL);
	copy = malloc(gnl_strlen(s) + 1);
	if (!copy)
		return (NULL);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);

	res = malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (!res)
		return (NULL);

	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}

	j = 0;
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}

	res[i + j] = '\0';
	return (res);
}

char	*gnl_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}