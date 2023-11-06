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

char    *get_next_line(int fd)
{
    char strori[BUFFER_SIZE + 1];
    static char *str;
    static int i;
    int j;
    static int k;
    char *strr;
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    if(k == 0)
    {
        j = read(fd, strori, BUFFER_SIZE);
        k++;
        strori[j] = '\0';
        str = ft_strdup(strori);
    } 
    if(i <= ft_strlen((const char *)str))
    {
        strr = ft_finder(str + i, '\n');
        i += ft_strlen((const char *)strr); 
        return (strr);
    }
    return (0);
}


int main()
{
    
        int fd = open("string.txt", O_RDONLY);
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        close(fd);
      

}