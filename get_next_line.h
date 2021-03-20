#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>  //remove
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <sys/resource.h>

# define FT_LIMIT_FD	RLIMIT_NOFILE
# define BUFFER_SIZE	6
# define EOL			1
# define FT_EOF			0
# define ERROR			-1

int				get_next_line(int fd, char **line);
void			*ft_memcpy(void *dest, const void *src, size_t n);
size_t			ft_strlen(const char *pointer);
char			*ft_strjoin(char *s1, char const *s2);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *str, int c);
#endif