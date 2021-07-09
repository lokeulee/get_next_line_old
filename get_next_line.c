#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		((unsigned char *)b)[index] = c;
		 index++;
	}
	return (b);
}

char	*ft_calloc(size_t count, size_t size)
{
	void	*heap;
	size_t	total_size;

	total_size = count * size;
	heap = (char *)malloc(total_size);
	if (!heap)
		return (NULL);
	ft_memset(heap, 0, total_size);
	return (heap);
}

int	get_good(char **str, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_substr(*str, 0, i);
		temp = ft_strdup(&((*str)[i + 1]));
		free(*str);
		*str = temp;
	}
	else
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	int			reader;
	char		buffer[BUFFER_SIZE + 1];
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	reader = 1;
	while (!(ft_strchr(str, '\n')) && reader > 0)
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader < 0)
			return (-1);
		if (!str)
			str = ft_calloc(1, 1);
		buffer[reader] = '\0';
		temp = ft_strjoin(str, buffer);
		free(str);
		str = temp;
	}
	return (get_good(&str, line));
}
