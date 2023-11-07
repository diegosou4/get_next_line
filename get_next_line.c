/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:52:58 by diegmore          #+#    #+#             */
/*   Updated: 2023/11/07 14:46:38 by diemorei         ###   ########.fr       */
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
char	*ft_strchr(char *str, int c)
{
	int	i;
	int	length_s;

	length_s = ft_strlen(str);
	i = 0;
	while (i < length_s)
	{
		if (str[i] == (char)c)
		{
			return ((char *)(str +( i + 1)));
		}
			
		i++;
	}
	if (str[i] == (char)c)
	{
		return ((char *)(str + length_s));
	}
	else
	{
		return (NULL);
	}
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

char *ft_finder(char *str, char c)
{
	int i;
	i = 0;
	char *strr;
	int j;
	j = 0;
	if(str == NULL)
		return (NULL);
	while(str[i] != '\0')
	{
		if(str[i] == c)
			break;
		i++;
	}
	strr = (char *)malloc(sizeof(char) * (i + 1) );
	if(!strr)
	{
		return (NULL);
	}	
	while(j != (i + 1))
	{
		strr[j] = str[j];
		j++;
	}
	strr[i + 1]	= '\0';
	return (strr);
}

char    *get_next_line(int fd)
{
    char strori[BUFFER_SIZE + 1];
    static char *str;
    int j;
    char *tmp;
	
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 )
        return (NULL);
    while((j = read(fd, strori, BUFFER_SIZE)) > 0)
	{
		strori[j] = '\0';
		if(!str)
		{
			str = ft_strdup(strori);
		}
		else
		{
			tmp = str;
			str = ft_strjoin(str, strori);
			free(tmp);
		}
	}
	if (str != NULL)
		tmp = ft_finder(str, '\n');
	if(tmp != NULL)
	{
		str =  ft_strchr(str, '\n');
		return (tmp);
	} 
    free(str);
    return (NULL);
}


int main()
{
    
        int fd = open("string.txt", O_RDONLY);
        char *str = get_next_line(fd);
		
		printf("[LINHA 1] %s  tamanho%i", str, ft_strlen(str));
		free(str);
      //  printf("[LINHA 2] %s", get_next_line(fd));
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
