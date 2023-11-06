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
    static char str[BUFFER_SIZE + 1];
    static int i;
    int j;
    char *strr;
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
   if((j = read(fd, str, BUFFER_SIZE)) > 0)
    {
        str[j] = '\0';
        strr = ft_finder(str, '\n');
        i += ft_strlen((const char *)strr);
        return (strr);
    }else
    {
        strr = ft_finder(str + i, '\n');
        i += ft_strlen((const char *)strr);
        return (strr);
    }
    return ("\n TESTE");
}


int main()
{
    
        int fd = open("string.txt", O_RDONLY);
        printf("%s", get_next_line(fd));
  

        close(fd);
      

}