#include "get_next_line.h"

char    *save_line(char *buffer)
{
    int     index;
    int     jndex;
    char    *heap;

    index = 0;
    jndex = 0;
    if (!buffer)
        return (0);
    while (buffer[index] && buffer[index] != '\n')
        index++;
    if (!buffer[index])
    {
        free(buffer);
        return (0);
    }
    heap = malloc(sizeof(char) * (ft_strlen(buffer) - index + 1));
    if (!heap)
        return (0);
    index++;
    while (buffer[index])
    {
        heap[jndex] = buffer[index];
        index++;
        jndex++;
    }
    heap[index] = '\0';
    free(buffer);
    return (heap);
}

char    *get_line(char *line)
{
    int     index;
    char    *heap;

    index = 0;
    if (!line)
        return (0);
    while (line[index] && line[index] != '\n')
        index++;
    heap = (char *)malloc(sizeof(char) * index + 1);
    if (!heap)
        return (0);
    index = 0;
    while (line[index] && line[index] != '\n')
    {
        heap[index] = line[index];
        index++;
    }
    heap[index] = '\0';
    return (heap);
}

int get_next_line(int fd, char **line)
{
    static char *str;
    int         reader;
    char        *buffer;

    if (fd < 0 || !line || BUFFER_SIZE <= 0)
        return (-1);
    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return (-1);
    reader = 1;
    while (!ft_strchr(str, '\n') && reader > 0)
    {
        if ((reader = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
        buffer[reader] = '\0';   
        str = ft_strjoin(str, buffer);
    }
    free(buffer);
    *line = get_line(str);
    str = save_line(str);
    if (reader == 0)
        return (0);
    return (1);
}