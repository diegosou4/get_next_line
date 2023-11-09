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

int 	ft_strchr(char *str, char c)
{
	size_t	i;
	size_t	length_s;

    if(!str)
        return(0);
	
    length_s = ft_strlen(str);
	i = 0;
	while (i < length_s)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
		return (0);
}
char *ft_join(char *buff, char *rest)
{
    char *str;
    size_t i;
    size_t j;
    size_t len;

    i = 0;
    j = 0;
    len = ft_strlen(buff) + ft_strlen(rest) + 1; 

    str = (char *) malloc(sizeof(char) * len);
    if(!str)
        return(NULL);
    while(rest && rest[j])
    {
        str[j] = rest[j];
        j++;
    }
    while(buff && buff[i])
    {
        str[j] = buff[i];
        i++;
        j++;
    }
    str[j] = '\0';
    return(str);
}
char    *ft_strjoin(char *buff, char *rest)
{
    char *str;
     if(!rest && !buff)
        return (NULL);
    if(!rest)
    {
        rest = (char *) malloc(sizeof(char) * 1);
        if(!rest)
        {
            return(NULL);
        }
        rest[0] = '\0';
    }
    str = ft_join(buff, rest);
    if(!str)
        return(NULL);

    return(str);
}
char *ft_returntmp(char *rest, int i)
{
    char *str;
    int j;
    j = 0;
    str = (char *) malloc(sizeof(char) * i);
    if(!str)
        return(NULL);
    while(j < i)
    {
        str[j] = rest[j];
        j++;
    }
    str[j] = '\0';
    return(str);
}
char    *ft_return(char *rest)
{
    int i;
    i = 0;
    char *str;

    if(!rest)
    {
        str = (char *) malloc(sizeof(char) * 1);
        if(!str)
            return(NULL);
        str[0] = '\0';
        return(str);
    }
    while(rest[i] != '\0')
    {
        if(rest[i] == '\n')
            break;
        i++;
    }
    if(rest[i] == '\n')
        i++;
    str = ft_returntmp(rest,i);
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
    str = (char *) malloc(sizeof(char) * i);
    if(!str)  
        return(NULL);
    while(j < i)
    {
        str[j] = rest[j + i];
        j++;
    }
    str[j] = '\0';
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
    tmp = (char *) malloc(sizeof(char) *( BUFFER_SIZE + 1));
    if(!tmp)
        return(NULL);
    while(line_read != 0 && (ft_strchr(rest, '\n' != 1)))
    {
    line_read = read(fd,tmp,BUFFER_SIZE);
    if(line_read < 0)
    {
        free(tmp);
        return(NULL);
    }
    tmp[line_read] = '\0';
    rest = ft_strjoin(tmp,rest);
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