


#include "get_next_line.h"


int ft_strlen(char *str)
{
    int i;

    i = 0;
    if(!str)
        return(0);
    while (str[i])
        i++;
    return(i);
}

char	*ft_strchr(char *s, int c)
{
	int i;

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

char    *ft_join(char *new_str,char *str, char *buffer)
{
    int i;
    int j;

    i = 0;
    j = 0;

    while(str && str[i])
    {
        new_str[i] = str[i];
        i++;
    }
    while(buffer && buffer[j])
    {
        new_str[i + j] = buffer[j];
        j++;
    }
    new_str[i + j] = '\0';
    return(new_str);
}


char    *ft_strjoin(char *str, char *buffer)
{
    char *new_str;

    if(!str)
    {
        str = (char *) malloc (sizeof(char) * 1);
        str[0] = '\0';
    }
    if(!str || !buffer)
        return(NULL);
    new_str = (char *)malloc((1 + ft_strlen(str)) + ft_strlen(buffer) * sizeof(char));
    if(!new_str)
        return(NULL);
    new_str = ft_join(new_str,str,buffer);
    free(str);
    return(new_str);
}

char    *ft_rnewline(char *str)
{
    int i;
    int j;
    char *new_line;
    i = 0;
    j = 0;
    if(str[i] == '\0')
        return(NULL);
    while(str[i] && str[i] != '\n')
         i++;
    if(str[i] == '\n')
        i++;
    new_line = (char *) malloc(sizeof(char) * (i + 1));
    if(!new_line)
        return(NULL);
    while(j < i)
    {
        new_line[j] = str[j];
        j++;
    }
    new_line[j] = '\0';
    return(new_line);
}



char	*ft_substr(char  *str,int start, int len_str)
{
	int	i;
	char	*subs;
    int sum;
    i = 0;
	if (!str)
		return (NULL);
    sum = len_str - start;
    subs = (char *) malloc(sizeof(char) * (sum + 1));
    if(!subs)
        return(NULL);
    while(str[start])
    {
        subs[i] = str[start];
        i++;
        start++;
    }
    subs[i] = '\0';
    free(str);
    return(subs);
}


char *get_next_line(int fd)
{
    static char *str;
    char *buffer;
    int bytes_read;

    bytes_read = 1;
    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!buffer)
        return(NULL);
    while(bytes_read != 0 && !(ft_strchr(str, '\n')))
    {
        bytes_read = read(fd,buffer, BUFFER_SIZE);
        if(bytes_read == -1)
        {
            free(buffer);
            return(NULL);
        }
        buffer[bytes_read] = '\0';
        str = ft_strjoin(str,buffer);
    }
    free(buffer);
    buffer = ft_rnewline(str);
    str = ft_substr(str, ft_strlen(buffer), ft_strlen(str));
    return(buffer);
}

int	main(void)
{
	char	*line;
	int		fd;
    int i;
    i = 0;
	fd = open("string.txt", O_RDONLY);
	//printf("\nFile Descriptor: %d\n\n", fd);
	while(i < 7)
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