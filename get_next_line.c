#include "get_next_line.h"
#include <fcntl.h>   // open
#include <stdio.h>   // printf
#include <unistd.h>  // close

// char *get_next_line(int fd)
// {
//     gnl_strlen()
// }



int	main(void)
{
	int		fd;
	size_t	n;

	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
	n = gnl_strlen("Hello");
	printf("strlen = %zu\n", n);
	close(fd);
	return (0);
}