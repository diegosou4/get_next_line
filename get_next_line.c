#include "get_next_line.h"


size_t     ft_strlen(char *str)
{
        size_t     i;
        i = 0;
        while (str[i] != '\0')
        {
                i++;
        }
        return (i);
}

int ft_strchr(char *buffer)
{
    size_t i;
    i = 0;
    while(buffer[i] != '\0')
    {
        if(buffer[i] == '\n')
            return (1);
        i++;
    }

    return(0);
}

char    *ft_strdup(char *src)
{
        char    *dest;
        size_t     size;
        size_t     i;

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


char    *ft_strjoin(char  *s1, char  *s2)
{
        size_t     size_s1;
        size_t     size_s2;
        size_t     i;
        size_t     j;
        char    *new;

        i = 0;
        j = 0;
        size_s1 = ft_strlen(s1);
        size_s2 = ft_strlen(s2);
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

void    readandreturn(int fd, char **rest)
{
    int j;
    int i;
    char *p;
    char *d;
    i = 1;
  
    while(i == 1)
    {
        p = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
        if(p == NULL)
        {
            free((*rest));
            return;
        }
        
        j = read(fd,p,BUFFER_SIZE);
        if(j == 0)
            i = 0;
        if(j == - 1)
        {
            free(p);
            return;
        }
            
        p[j] = '\0';
        if(j > 0)
        {
           if((*rest) == NULL)
              (*rest) = ft_strdup(p);
            else
            {
                d = (*rest);
                (*rest) = ft_strjoin((*rest), p);
                free(d);
            }
            if (ft_strchr((*rest)) == 1)
                i = 0;
            else 
                i = 1;
        }
           free(p);
    }

}


char    *ft_substr(char *s, int start, int len)
{
   char *str;
   int i;
   i = 0;
   int cal;

   cal = len - start; 
   str = (char *)malloc(sizeof(char) * cal + 1);
   if(!str)
    return(0);

  while(i < cal)
    {
        str[i] = s[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return (str);
}


void cleanandreturn(char **rest, char **buf)
{
    char *tmp;
    int i;
    int j;
    j = 0;
    i = 0;
    while((*rest)[i] != '\0')
    {
            if((*rest)[i] == '\n')
                {
                    i++;
                    break;
                }
            i++;
    }
    (*buf) = (char *) malloc(sizeof(char) * i + 1);
    if(!(*buf))
    {
        free((*rest));
        return;
    }
    while(j < i)
    {
        (*buf)[j] = (*rest)[j];
        j++;
    }
    (*buf)[j] = '\0';
    tmp = (*rest);
    (*rest) = ft_substr(tmp,j,ft_strlen(tmp));
    free(tmp);

}




char *get_next_line(int fd)
{
    static char *rest;
    char *buf;

    

    if(fd < 0 || BUFFER_SIZE <= 0 )
        return (NULL);

    readandreturn(fd,&rest);
    cleanandreturn(&rest, &buf);
    return(buf);

}

/*
int	main(void)
{
	char	*line;
	int		fd;

	fd = open("string.txt", O_RDONLY);
	//printf("\nFile Descriptor: %d\n\n", fd);
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
        line = get_next_line(fd);
		printf("%s", line);
		free(line);
        line = get_next_line(fd);
		printf("%s", line);
		free(line);
	//printf("\nReturn value of read: %zd", read(fd, line, BUFFER_SIZE));
	close(fd);
	return (0);
}*/