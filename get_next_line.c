#include "get_next_line.h"

int		get_good(char **str, char **line, int reader)
{
    int		i;
    char	*temp;

	if (reader < 0)
		return (-1);
	while ((*str)[i] && (*str)[i] != '\n')
		i++;
	if ((*str)[i] == '\n')
	{
		*line = ft_substr(*str, 0, i);
		temp = ft_strdup(&((*str)[i + 1]));
		free(*str);
		*str = temp;
	}
	else if ((*str)[i] == '\0')
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
    static char	*str;
    int			reader;
    char		buffer[BUFFER_SIZE + 1];
    char		*temp;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    reader = 1;
    while (!ft_strchr(str, '\n') && reader > 0)
    {
        reader = read(fd, buffer, BUFFER_SIZE);
		if (reader < 0)
			return (-1);
        if (!str)
			str = ft_calloc(1,1);
		buffer[reader] = '\0';
        temp = ft_strjoin(str, buffer);
        free(str);
        str = temp;
    }
    return (get_good(&str, line, reader));
}