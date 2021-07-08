#include "get_next_line.h"

void	freestr(char **str)
{
	if (str || *str)
	{
		free(*str);
		*str = NULL;
	}
}

size_t     ft_strlen(const char *s)
{
    int index;

    index = 0;
    if (!s)
        return (0);
    while (s[index] != '\0')
        index++;
    return (index);
}

char    *ft_strdup(const char *str)
{
    size_t  len;
    size_t  index;
    char    *array;

    len = ft_strlen(str);
    array = malloc(sizeof(char) * (len + 1));
    if (!array)
        return (NULL);
    index = 0;
    while (index < len + 1)
    {
        array[index] = str[index];
        index++;
    }
    array[index] = '\0';
    return (array);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*heap;
	size_t	index;
	size_t	strlen;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
		len = 0;
	if (len > strlen)
		len = strlen - start;
	heap = (char *)malloc(sizeof(char) * (len + 1));
	if (heap == NULL)
		return (NULL);
	index = 0;
	while (index < len)
	{
		heap[index] = s[start];
		index++;
		start++;
	}
	heap[index] = '\0';
	return (heap);
}

int    ft_strchr(const char *s, int c)
{
    int     i;

    i = 0;
    if (!s)
        return (0);
    while(s[i])
    {
        if (s[i] == (char)c)
            return (1);
        i++;
    }
    return (0);
}

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

void	*ft_calloc(size_t	count, size_t	size)
{
	void	*heap;
	size_t	total_size;

	total_size = count * size;
	heap = malloc(total_size);
	if (!heap)
		return (NULL);
	ft_memset(heap, 0, total_size);
	return (heap);
}	

char    *ft_strjoin(const char *s1, const char *s2)
{
    size_t  index;
    int     len;
    char    *heap;

    len = ft_strlen(s1) + ft_strlen(s2);
    heap = (char *)malloc(sizeof(char) * (len + 1));
    if (!heap)
        return (NULL);
    index = 0;
    while (s1 && *s1)
    {
        heap[index] = *s1;
        s1++;
        index++;
    }
    while (s2 && *s2)
    {
        heap[index] = *s2;
        s2++;
        index++;
    }
    heap[index] = '\0';
    return (heap);
}