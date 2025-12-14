#include "get_next_line.h"
#include <fcntl.h>   // open
#include <stdio.h>   // printf
#include <unistd.h>  // close

char *get_next_line(int fd)
{
	static char	*stash;

	(void)fd;
	if (!stash)
		stash = gnl_strdup("INIT");
	return (stash);
}

int	main(void)
{
	int		fd;
	char    *line;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	line = get_next_line(fd);
    printf("line = %s\n", line);
	close(fd);
	return (0);
}

// cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 \
// get_next_line.c get_next_line_utils.c \
// -o test && ./test