/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:52:58 by diegmore          #+#    #+#             */
/*   Updated: 2023/11/06 11:08:36 by diemorei         ###   ########.fr       */
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
    static int i;
    int k;
    k = 0;
    int j;
    if(fd < 0 || BUFFER_SIZE <= 0 || i > BUFFER_SIZE)
        return (NULL);
    tmp = calloc(2, sizeof(char));
    str = malloc(sizeof(char) * BUFFER_SIZE + 1);
    while(i <= BUFFER_SIZE)
    {
        j = read(fd,tmp, 1);
        if(tmp[0] != '\n' && j > 0)
        {
            str[k] = tmp[0];
        }
        if(tmp[0] == '\n')
        {
            str[k] = '\n';
            i++;
            k++;
            break;
        }   
        i++;
        k++;
    }
    str[k] = '\0';
    str = ft_strdup(str);
    return (str);
}


int main()
{
    
        int fd = open("string.txt", O_RDONLY);
        char *str = get_next_line(fd);
        printf("%s", str);
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));

}