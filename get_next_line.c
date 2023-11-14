#include "get_next_line.h"


int ft_strlen(char *str)
{
    int i;

    i = 0;
    if(!str)
        return(0);
    while (str[i] && str)
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

char    *ft_join(char *new_str,char *line,char *str)
{
    int i;
    int j;
    j = 0;
    i = 0;
    while(line && line[i])
    {
        new_str[i] = line[i];
        i++;
    }
    while(str && str[j])
    {
        new_str[i + j] = str[j];
        j++;
    }
    new_str[i + j] = '\0';
    if(line)
        free(line);
    return(new_str);

}
char *ft_cutline(char *line)
{
    int i;
    int j;
    i = 0;
    j = 0;
    if(!line || line[0] == '\0')
        return(NULL);
    while (line && line[i] && line[i] != '\n')
        i++;
    if(line[i] == '\n')
        i++;
    char strcut[i + 1];
    while(j < i)
    {
        strcut[j] = line[j];
        j++;
    }
    strcut[j] = '\0';
    if(line)
        free(line);
    line = strcut;
    return(line);
}

char    *ft_strjoin(char *line, char *str)
{
    char *new_str;
    int i;
    int j;

    i = ft_strlen(line);
    j = ft_strlen(str);
    if(i == 0 && j == 0)
        return(NULL);
    if(!line && !str)
        return(NULL);
    new_str = (char *)malloc((1 + ft_strlen(line)) + ft_strlen(str) * sizeof(char));
    if(!new_str)
        return(NULL);
    line = ft_join(new_str,line, str);
    return(line);
}


char    *ft_read(char *str, char *line, int fd)
{
    int bytes_reads;
    bytes_reads = 1;
    while (bytes_reads != 0 && !(ft_strchr(str, '\n')))
    {
        bytes_reads = read(fd, str, BUFFER_SIZE);
        if(bytes_reads == - 1 )
        {
            return(NULL);
        }
        if(bytes_reads == 0)
            break;
        str[bytes_reads] = '\0';
        line = ft_strjoin(line,str);
    }
    return(line);
}
void    clearmystr(char *p)
{
    int i;
    i = 0;
    int j;
    j = 0;
    while(p[i] && p)
    {
        if(p[i] == '\n')
        {
            p[i] = 0;
            i++;
            break;
        }
        p[i] = 0;
        i++;
    }
    while(p[i] && p)
    {
        p[j] = p[i];
        j++;
        i++;
    }
    p[j] = 0;
}

char    *get_next_line(int fd)
{
    static char str[BUFFER_SIZE + 1];
    char *line;
    char *p;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    p = str;
    line = NULL;
    line = ft_strjoin(line, p);
    line = ft_read(str, line, fd);
    line = ft_cutline(line);
    p = str;
    clearmystr(p);
    return(line);
}


int main()
{
    int fd;

    fd = open("string.txt", O_RDONLY);
    
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));

    close(fd);

}