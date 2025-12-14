#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);

/* utils */
size_t	gnl_strlen(const char *s);
// char	*gnl_strchr(const char *s, int c);
 char	*gnl_strjoin(char const *s1, char const *s2);
 char	*gnl_strdup(const char *s1);

#endif