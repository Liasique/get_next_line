#include "get_next_line.h"
#include <fcntl.h>   // open
#include <stdio.h>   // printf
#include <unistd.h>  // close

char *get_next_line(int fd)
{
	static char	*stash;

	(void)fd;
	if (!stash)
		stash = gnl_strdup("");
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