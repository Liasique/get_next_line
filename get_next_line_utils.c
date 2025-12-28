/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olglukia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:09:54 by olglukia          #+#    #+#             */
/*   Updated: 2025/12/16 11:25:03 by olglukia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*gnl_strdup(const char *s)
{
	size_t	i;
	char	*copy;

	if (!s)
		return (NULL);
	copy = (char *)malloc(gnl_strlen(s) + 1);
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

void	*gnl_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*gnl_strjoin_and_free(char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*res;

	if (!s1)
		return (s1 = gnl_strdup(s2));
	if (!s2)
		return (free(s1), NULL);
	len1 = gnl_strlen(s1);
	len2 = gnl_strlen(s2);
	res = (char *)malloc(len1 + len2 + 1);
	if (!res)
		return (free(s1), NULL);
	gnl_memcpy(res, s1, len1);
	gnl_memcpy(res + len1, s2, len2 + 1);
	free(s1);
	return (res);
}
