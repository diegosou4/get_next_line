/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegmore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:52:58 by diegmore          #+#    #+#             */
/*   Updated: 2023/11/02 16:53:00 by diegmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    char *str;
    int i;
    i = 0;
    str = malloc(sizeof(char) * BUFFER_SIZE);
    while(str[i] != '\n')
    {
        read(fd, str + i, 1);
        if(str[i] == '\n')
            break;
        i++;
    }
    str[i + 1] = '\0';
    ft_strdup(str);
    return (str);

}


int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        int fd = open(argv[1], O_RDONLY);
        char *str = get_next_line(fd);
        printf("%s", str);     
        str = get_next_line(fd);
        printf("%s", str);
        str = get_next_line(fd);
        printf("%s", str);
        str = get_next_line(fd);
        printf("%s", str);
    }

}