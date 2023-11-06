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
    char *strr;
    if(fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
        return (NULL);
    if((j = read(fd, strori, BUFFER_SIZE)) != 0)
    {
        strori[j] = '\0';
        str = ft_strdup(strori);
    } 
    if(i <= BUFFER_SIZE)
    {
        strr = ft_finder(str + i, '\n');
           printf("%s debug", (str + i));
        i += ft_strlen((const char *)strr); 
       // printf(" \n %d digito da ascii \n", str[i]);
     //   printf(" \n %i posicao \n", i);
        printf(" \n %li retorno strlen \n", ft_strlen((const char *)strr));
        return (strr);
    }
    return (str);
}


int main()
{
    
        int fd = open("string.txt", O_RDONLY);
        printf("%s", get_next_line(fd));
        printf("%s", get_next_line(fd));
        close(fd);
      

}