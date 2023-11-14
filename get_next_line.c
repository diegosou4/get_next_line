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

int ft_nline(char *buff)
{
    int i;
    i = 0;
    if(!buff || buff[0] == '\0')
        return(0);
    while (buff[i] && buff[i] != '\n')
        i++;
    if(buff[i] == '\n')
        i++;
    return(i);
}

char    *ft_cutline(char *buff, int i)
{
    char *str;
    str = (char *) malloc((i + 1) * sizeof(char));
    i = 0;
    while(buff[i] && buff[i] != '\n')
    {
        str[i] = buff[i];
        i++;
    }
    if(buff[i] == '\n')
    {
        str[i] = '\n';
        i++;
    }
    str[i] = '\0';
    return(str);
}
void ft_wordjoin(char *buffer,char *str)
{
    int i;
    int j;
    i = 0;
    j = 0;

    while(str[i])
        i++;
    while(buffer[j])
    {
        str[i + j] = buffer[j];
        j++;
    }
    str[i + j] = '\0';
    if(buffer)
        free(buffer);
}


void    ft_read(char *str,int fd)
{
    int bytes_reads;
    char *buffer;
    
    buffer = NULL;
    bytes_reads = 1;
    while (bytes_reads != 0 && !(ft_strchr(buffer, '\n')))
    {
        buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
        if(!buffer)
            return;
        bytes_reads = read(fd,buffer,BUFFER_SIZE);
        if(bytes_reads == -1)
        {
            free(buffer);
            return;
        }
        if(bytes_reads == 0)
        {
            free(buffer);
            return;
        }
        buffer[bytes_reads] = '\0';
        ft_wordjoin(buffer, str);
        buffer = NULL;
    }
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
    char *p;
    int i;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);
    p = str;
    clearmystr(p);
    ft_read(p, fd);
    i = ft_nline(p);

    return(ft_cutline(p , i));
}

/*
int main()
{
    int fd;
    char *p;

    fd = open("string.txt", O_RDONLY);
    p = get_next_line(fd);
    printf("%s", p);
    free(p);
    p = get_next_line(fd);
    printf("%s", p);
    free(p);
    p = get_next_line(fd);
    printf("%s", p);
    free(p);

    close(fd);

}*/