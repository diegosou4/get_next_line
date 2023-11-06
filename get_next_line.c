/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:52:58 by diegmore          #+#    #+#             */
/*   Updated: 2023/11/06 10:43:28 by diemorei         ###   ########.fr       */
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

char    *get_next_line(int fd)
{
    char *str;
    char *tmp;
    char buf[BUFFER_SIZE + 1];
    static int i;
    int j;
    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = malloc(sizeof(char) * BUFFER_SIZE);
    j = read(fd, str, BUFFER_SIZE);
    while(str[0] && str[i] != '\n')
    {
        if(str[i] == '\0')
            break;
        buf[i] = str[i];
        i++;
    }
    if(str[i] == '\n')
    {
        buf[i] = str[i];
        i++;
    }
    buf[i] = '\0';
    tmp = ft_strdup(buf);
    return (tmp);

}


int main()
{
    
        int fd = open("string.txt", O_RDONLY);
        char *str = get_next_line(fd);
        printf("%s", str);
        printf("%s", get_next_line(fd));


}