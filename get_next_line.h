#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

void	freestr(char **str);
int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
void	*ft_calloc(size_t	count, size_t	size);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
int	    ft_strchr(const char *str, int c);
char    *ft_strdup(const char *str);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif

