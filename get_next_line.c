/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:52:58 by diegmore          #+#    #+#             */
/*   Updated: 2023/11/07 11:59:48 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	size_t	length_s;

	length_s = ft_strlen((char *)str);
	i = 0;
	while (i < length_s)
	{
		if (str[i] == (char)c)
			return ((char *)(str +( i + 1)));
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
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen((char *)src);
	dest = (char *)calloc((size + 1), sizeof(char));
	if (!dest)
		return (NULL);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
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
	i++;
	strr = (char *)malloc(sizeof(char) * i );
	if(!strr)
		return (NULL);
	while(j != i)
	{
		strr[j] = str[j];
		j++;;
	}
	strr[i]	= '\0';
	
	return (strr);
}

char    *get_next_line(int fd)
{
    char *strori;
    static char *str;
    int j;
    char *tmp;
	
	strori = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0 || strori == NULL)
        return (NULL);
    while((j = read(fd, strori, BUFFER_SIZE)) > 0)
	{
		strori[j] = '\0';
		if(!str)
		{
			str = ft_strdup(strori);
			free(strori);
		}	
		else
			str = ft_strjoin(str, strori);
	}
	tmp = ft_finder(str, '\n');
	if(tmp != NULL)
	{
		str =  ft_strchr(str, '\n');
		return (tmp);
	} 
	free(str);
	free(strori);
    return (NULL);
}


int main()
{
    
        int fd = open("string.txt", O_RDONLY);
        
		printf("[LINHA 1] %s", get_next_line(fd));
        printf("[LINHA 2] %s", get_next_line(fd));
        printf("[LINHA 3] %s  barra ene\n", get_next_line(fd));
        printf("[LINHA 4] %s", get_next_line(fd));
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
      

}