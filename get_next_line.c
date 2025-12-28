/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olglukia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:47:08 by olglukia          #+#    #+#             */
/*   Updated: 2025/12/18 09:28:26 by olglukia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	r;

	if (!stash)
		stash = gnl_strdup("");
	if (!stash)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	r = 1;
	while (r > 0 && !gnl_strchr(stash, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (free(buf), free(stash), NULL);
		buf[r] = '\0';
		if (r > 0)
		{
			stash = gnl_strjoin_and_free(stash, buf);
			if (!stash)
				return (free(buf), NULL);
		}
	}
	return (free(buf), stash);
}

static char	*extract_line(const char *stash)
{
	char	*line;
	size_t	i;
	size_t	j;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = stash[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*keep_rest(char *stash)
{
	char	*rest;
	size_t	i;
	size_t	j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	i++;
	rest = (char *)malloc(gnl_strlen(stash + i) + 1);
	if (!rest)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (!stash)
		return (NULL);
	if (stash[0] == '\0')
		return (free(stash), stash = NULL, NULL);
	line = extract_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = keep_rest(stash);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int    main(void)
{
    int        fd;
    char    *line;

    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
	{
		printf("error");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
    close(fd);
    return (0);
}*/
