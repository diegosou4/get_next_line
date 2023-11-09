#include "get_next_line.h"


size_t     ft_strlen(char *str)
{
        size_t     i;
        i = 0;
        if(!str[i])
            return(0);
        while (str[i] != '\0')
        {
                i++;
        }
        return (i);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	if (c == 0)
	{
		i = ft_strlen((char *)s);
		return (&s[i]);
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}
char *ft_join(char *dest,char *buff, char *rest)
{
    size_t i;
    size_t j;
    size_t len;

    i = 0;
    j = 0;
   
    len = ft_strlen(buff) + (ft_strlen(rest) + 1);
    dest = (char *) malloc(sizeof(char) * len);
    if(!dest)
        return(NULL);
    while(rest && rest[j])
    {
        dest[j] = rest[j];
        j++;
    }
    while(buff && buff[i])
    {
        dest[j] = buff[i];
        i++;
        j++;
    }
    dest[j] = '\0';
    return(dest);
}
char    *ft_strjoin(char *rest, char *buff)
{
    char *str;
    char *tmp;
     if(!rest && !buff)
        return (NULL);
    if(!rest)
    {
        rest = (char *) malloc(sizeof(char) * 1);
        rest[0] = '\0';
    }
    str = (char *)malloc((1 + ft_strlen(rest)) + ft_strlen(buff) * sizeof(char));
    if(!str)
        return(NULL);
    tmp = str;
    str = ft_join(str,buff, rest);
    free(tmp);
    free(rest);
    return(str);
}


char    *ft_return(char *rest)
{
    int i;
    char *str;
    i = 0;
    if(!rest || !rest[0])
        return(NULL);
    while(rest[i] && rest[i] != '\n')
        i++;
    if(rest[i] == '\n')
        i++;
    str = (char *) malloc( sizeof(char) * (i + 1));
    if(!str)
        return(NULL);
    i = 0;
    while(rest[i] && rest[i] != '\n')
    {
        str[i] = rest[i];
        i++;
    }
    if(rest[i] == '\n')
        str[i++] = '\0';
    else
        str[i] = '\0';
    return(str);
}

char *clearmyrest(char *rest)
{
    char *str;
    int i;
    int j;
    j = 0;
    i = 0;
    if(!rest)
        return(NULL);
    while(rest[i] != '\n' && rest[i])
        i++;
    if(rest[i] == '\n')
        i++;
    str = (char *) malloc(sizeof(char) * i + 1);
    if(!str)  
        return(NULL);
    while(j < i && rest[j + i])
    {
        str[j] = rest[j + i];
        j++;
    }
    str[j] = '\0';
    free(rest);
    return(str);
}   
char *get_next_line(int fd)
{
    static char *rest;
    char *tmp;
    int line_read;

    line_read = 1;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    tmp = (char *) malloc(sizeof(char) *(BUFFER_SIZE + 1));
    if(!tmp)
        return(NULL);
    while (!(ft_strchr(rest, '\n')) && line_read != 0)
    {
    line_read = read(fd,tmp,BUFFER_SIZE);
    if(line_read == -1)
    {
        free(tmp);
        return(NULL);
    }
    tmp[line_read] = '\0';
    rest = ft_strjoin(rest,tmp);
    }
    free(tmp);
    tmp = ft_return(rest);
    rest = clearmyrest(rest);
    return(tmp);
}


int	main(void)
{
	char	*line;
	int		fd;

	fd = open("string.txt", O_RDONLY);
	//printf("\nFile Descriptor: %d\n\n", fd);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	//printf("\nReturn value of read: %zd", read(fd, line, BUFFER_SIZE));
	close(fd);
	return (0);
}