/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:52:58 by diegmore          #+#    #+#             */
/*   Updated: 2023/11/07 18:39:29 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int	size;
	int	i;

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

char	*ft_strjoin(char  *s1, char  *s2)
{
	int	size_s1;
	int	size_s2;
	int	i;
	int	j;
	char	*new;

	i = 0;
	j = 0;
	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	new = (char *)malloc(((size_s1 + size_s2) + (1)) * sizeof(char));
	if (!new || (!s1 && !s2))
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

char *ft_finder(char *str)
{
	int i;
	char *n_str;
	i = 0;
	if(str == NULL)
		return (0);
	while(str[i] != '\0')	
	{
		if(str[i] == '\n')
		{
			i++;
			break;
		}	
		i++;
	}
	n_str = (char *) malloc(sizeof(char) * i);
	if(n_str == NULL)
		return (NULL);
	n_str[i] = '\0';
	while(i-- > 0)
	{
		n_str[i] = str[i];
	}
	return(n_str);
}

char	*ft_substr(char  *s, int start, int len)
{
	int	i;
	int	len_s;
	char	*subs;
	char	*subre;

	if (!s)
		return (NULL);
	if(start == len)
		return(NULL);
	len_s = ft_strlen((char *)s);
	i = 0;
	subs = (char *)malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	while (i < len && start < len_s)
	{
		subs[i] = s[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	subre = ft_strdup(subs);
	free(subs);
	return (subre);
}

char    *get_next_line(int fd)
{
    char strori[BUFFER_SIZE + 1];
    static char *str;
    int j;
    char *tmp;
	char *n;
	
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 )
        return (NULL);
    while((j = read(fd, strori, BUFFER_SIZE)) > 0)
	{
		strori[j] = '\0';
		if(!str)
			str = ft_strdup(strori);
		else
		{
			tmp = str;
			str = ft_strjoin(str, strori);
			free(tmp);
		}
	}
	if(str != NULL)
	{
		tmp = ft_finder(str);
		n = str;
		str = ft_substr(str, ft_strlen(tmp),ft_strlen(str));
		free(n);
		return(tmp);
	}
    return (NULL);
}


int main()
{
    
        int fd = open("string.txt", O_RDONLY);
        char *str = get_next_line(fd);
		
		printf("[LINHA 1] %s \n", str);
		free(str);
       	//printf("[LINHA 2] %s \n", get_next_line(fd));
    //    printf("[LINHA 3] %s  barra ene\n", get_next_line(fd));
       // printf("[LINHA 4] %s", get_next_line(fd));
        /*
		printf("[LINHA 5] %s", get_next_line(fd));
        printf("[LINHA 6] %s", get_next_line(fd));
        printf("[LINHA 7] %s", get_next_line(fd));
        printf("[LINHA 8] %s", get_next_line(fd));
		printf("[LINHA 9] %s", get_next_line(fd));
		printf("[LINHA 10] %s", get_next_line(fd));
		printf("[LINHA 11] %s", get_next_line(fd));
		printf("[LINHA 12] %s", get_next_line(fd));
		printf("[LINHA 13] %s", get_next_line(fd));
		printf("[LINHA 14] %s", get_next_line(fd));
		*/
        close(fd);
      
	return (0);
}
