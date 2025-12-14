#include "get_next_line.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	r;
	char	*tmp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free(stash), NULL);
	if (!stash)
		stash = gnl_strdup("");
	if (!stash)
		return (free(buf), NULL);
	r = 1;
	while (r > 0 && !gnl_strchr(stash, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r < 0)
			return (free(buf), free(stash), NULL);
		buf[r] = '\0';
		if (r > 0)
		{
			tmp = stash;
			stash = gnl_strjoin(stash, buf);
			free(tmp);
			if (!stash)
				return (free(buf), NULL);
		}
	}
	free(buf);
	return (stash);
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

static char	*keep_rest(char *stash)
{
	char	*rest;
	size_t	i;
	size_t	j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	i++;
	if (!stash[i])
		return (free(stash), NULL);
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
	line = extract_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = keep_rest(stash);
	return (line);
}

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
// get_next_line.c get_next_line_utils.c main.c -o gnl_test