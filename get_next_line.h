/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olglukia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:59:49 by olglukia          #+#    #+#             */
/*   Updated: 2025/12/16 11:14:03 by olglukia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
/* utils */
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin_and_free(char *s1, char const *s2);
char	*gnl_strdup(const char *s1);
void	*gnl_memcpy(void *dst, const void *src, size_t n);

#endif
