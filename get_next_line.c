#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i] != '\0')
        i++;
    return(i);
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

char *ft_strdup(char *buffer)
{
    char *str;
    int j;
    int i;
    i = ft_strlen(buffer);
    j = 0;
    str  = (char *) malloc(sizeof(char) * (i + 1));
    if(str == NULL)
        return(NULL);
    while(j < i)
    {
        str[j] = buffer[j];
        j++;
    }
    str[i] = '\0';
    return str;
}

int ft_strrchr(char *buffer, int j)
{
    int i;
    i = 0;
    buffer[j] = '\0';
    while(buffer[i] != '\0')
    {
        if(buffer[i] == '\n')
            return (1);
        i++;
    }

    return(0);
}

int	ft_strrchr_v(char **str, char **tmp)
{
	int	i;
    int j;
    j = 0;
	i = 0;
	while ((*str)[i])
    {
		if ((*str)[i] == '\n')
            {
                i++;
                (*tmp) =  (char *) malloc(sizeof(char) * i );
                while(j < i)
                {
                    (*tmp)[j] = (*str)[j];
                    j++;
                }
                (*tmp)[j] = '\0';
                (*str) = ft_substr((*str),i, ft_strlen(*str));
                if((*str) == NULL)
                {
                    return(0);
                } else {
                    return (1);
                }
            }
        i++;
	}
    (*tmp) = ft_strdup((*str));
	return (0);
}



char	*ft_strjoin(char *s1, char *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
    if (s1 == NULL && s2 == NULL)
    {
        return (NULL);
     }
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new = (char *)malloc(((size_s1 + size_s2) + (1)) * sizeof(char));
	if (!new )
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

int readline(int fd, char *buffer, char **str)
{
    int j;
    char *s;
    j = 0;
    while((j = read(fd, buffer, BUFFER_SIZE)) > 0 && ft_strrchr(buffer, j) != 0)
    {
        buffer[j] = '\0';
            if(*str == NULL)
            {
                *str = ft_strdup(buffer);
            }
            else
            {
                s = (*str);
                (*str) = ft_strjoin(*str,buffer);
                free(s);
                if((*str))
                    return(NULL);
            }
    }   
    if(j == -1)
    {
        if(*str != NULL)
             free((*str));
     return (-1);
    }
    return (j);
}

char *get_next_line(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    static char *str;
    char *tmp;

    if(fd < 0 || BUFFER_SIZE <= 0)
        return(NULL);

    if(readline(fd, buffer, &str) == -1)
            return (NULL);
    ft_strrchr_v(&str, &tmp);        
    return(tmp);
}

int main(void)
{
    int fd = open("string.txt", O_RDONLY);
    char *s = get_next_line(fd);
    printf("%s", s);
    free(s);
    s = get_next_line(fd);
    printf("%s", s);
    free(s);
    close(fd);
    return 0;
}