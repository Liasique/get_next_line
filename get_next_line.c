#include "get_next_line.h"
#include <fcntl.h>   // open
#include <stdio.h>   // printf
#include <unistd.h>  // close

char	*get_next_line(int fd)
{
	static char	*stash;
	char		buf[2];
	ssize_t		r;
	char		*tmp;

	if (fd < 0)
		return (NULL);
	if (!stash)
		stash = gnl_strdup("");
	if (!stash)
		return (NULL);

	r = 1;
	while (r > 0 && !gnl_strchr(stash, '\n'))
	{
		r = read(fd, buf, 1);
		if (r < 0)
			return (NULL);
		if (r == 0)
			break;
		buf[1] = '\0';
		tmp = stash;
		stash = gnl_strjoin(stash, buf);
		free(tmp);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

int	main(void)
{
	int		fd;
	char	*line1;
	char	*line2;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	line1 = get_next_line(fd);
	printf("line1 = %s\n", line1);
	line2 = get_next_line(fd);
	printf("line2 = %s\n", line2);
	close(fd);
	return (0);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
// get_next_line.c get_next_line_utils.c \
// -o test && ./test