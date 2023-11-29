/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:44:32 by diegmore          #+#    #+#             */
/*   Updated: 2023/11/14 16:44:48 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char *str, int start, int len_str)
{
	int		i;
	char	*subs;
	int		sum;

	i = 0;
	sum = len_str - start;
	if (sum == 0 || !str)
	{
		free(str);
		return (NULL);
	}
	subs = (char *)malloc(sizeof(char) * (sum + 1));
	if (!subs)
		return (NULL);
	while (str[start])
	{
		subs[i] = str[start];
		i++;
		start++;
	}
	subs[i] = '\0';
	free(str);
	return (subs);
}

void	ft_free(char **str, char *buffer)
{
	free(buffer);
	free((*str));
	(*str) = NULL;
}

char	*get_next_line(int fd)
{
	static char	*str[FD_MAX];
	char		*buffer;
	int			bytes_read;

	bytes_read = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (bytes_read != 0 && !(ft_strchr(str[fd], '\n')))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			ft_free(&str[fd], buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		str[fd] = ft_strjoin(str[fd], buffer);
	}
	free(buffer);
	buffer = ft_rnewline(str[fd]);
	str[fd] = ft_substr(str[fd], ft_strlen(buffer), ft_strlen(str[fd]));
	return (buffer);
}
/*
#include <stdio.h>

int	main(void)
{
    int fd;
    int fd1;

    fd = open("string.txt", O_RDONLY);
    char *p;
    p = get_next_line(fd);
    printf("%s", p);
    free(p);
    fd1 = open("text.txt", O_RDONLY);
    p  = get_next_line(fd1);
    printf("%s", p);
    free(p);    
    p = get_next_line(fd);
    printf("%s", p);
    free(p);

}*/
