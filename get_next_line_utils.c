#include "get_next_line.h"

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

