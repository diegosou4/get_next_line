#include "get_next_line.h"

int     ft_strlen(char *str)
{
        int     i;

        i = 0;
        while (str[i] != '\0')
        {
                i++;
        }
        return (i);
}

char    *ft_strjoin(char  *s1, char  *s2)
{
        int     size_s1;
        int     size_s2;
        int     i;
        int     j;
        char    *new;

        i = 0;
        j = 0;
        size_s1 = ft_strlen(s1);
        size_s2 = ft_strlen(s2);
        if(!s1 || !s2)
            return(NULL);
        new = (char *)malloc(((size_s1 + size_s2) + (1)) * sizeof(char));
        if (!new)
                return (0);
        while (s1[i] != '\0')
        {
                new[i] = s1[i];
                i++;
        }
        while (s2[j] != '\0')
                new[i++] = s2[j++];
        new[i] = '\0';
        return (new);
}

char    *ft_strdup(char *src)
{
        char    *dest;
        int     size;
        int     i;

        i = 0;
        size = ft_strlen(src);
        dest = (char *)malloc((size + 1)* sizeof(char));
        if (!dest)
        {
                free(dest);
                return (NULL);
        }
        while (i < size)
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';
        return (dest);
}

int readandgive(char **str, char *buffer, int fd)
{
    int j;
    char *tmp;
    j = 0;
    if((j = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[j] = '\0';
        if(!(*str))
            (*str) = ft_strdup(buffer);
        else
        {
            tmp = (*str);
            (*str) = ft_strjoin((*str),buffer);
            free(tmp);
        }
    } 
    return(j);
}

int ft_strrchr(char *buffer)
{
    int i;
    i = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] == '\n')
            return (1);
        i++;
    }

    return(0);
}
char	*ft_strlcpy(char *src, int dstsize)
{
	int	index;
    char *dest;

    dest = (char *)malloc(sizeof(char) * dstsize);
	index = 0;
	if (dstsize == 0)
		return (NULL);
	while (src[index] && index < dstsize - 1)
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (dest);
}

void ft_finder(char **str, char **linereturn)
{
    int i;
    char *n_str;
    i = 0;
    if(*str == NULL)
        return;
    while((*str)[i] != '\0')
    {
            if((*str)[i] == '\n')
            {
                n_str = ft_strlcpy((*str), i + 2);
                (*linereturn) = n_str;
                return;
            }
            i++;
    }
    (*linereturn) = ft_strdup((*str));
}

char    *ft_substr(char *s, int start, int len)
{
    char *subs;
    int i;

    i = 0;
    if(start >= len)
        return (NULL);
    if(!s)
        return(NULL);
    subs = (char *)malloc((len + 1) * sizeof(char));
    if(!subs)
    {
        return (NULL);
    }
    while(i < len && start < len)
    {
        subs[i] = s[start];
        i++;
        start++;
    }
    subs[i] = '\0';
    return subs;
}

char    *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    static char *str;
    char *tmp;
    char *s;

    if(fd < 0 || BUFFER_SIZE <= 0 )
        return (NULL);
    while(readandgive(&str,buffer,fd) > 0)
    {
        if(ft_strrchr(str))
            break;
    }
    if(str)
    {
        ft_finder(&str, &tmp);
        s = str;
        if (tmp) {
            str = ft_substr(str, ft_strlen(tmp), ft_strlen(str));
            free(s);
            return(tmp);
        } else {
            tmp = str;
            free(str);
            return(tmp);
        }
    }
    return(NULL);
}

int	main(void)
{
	char	*line;
	int		fd;
	int		i;

	fd = open("string.txt", O_RDONLY);
	//printf("\nFile Descriptor: %d\n\n", fd);
	i = 1;
	while (i <= 5)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
	//printf("\nReturn value of read: %zd", read(fd, line, BUFFER_SIZE));
	close(fd);
	return (0);
}