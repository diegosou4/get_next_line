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
    char *tmp;
    char buf[BUFFER_SIZE + 1];
    static int i;
    int j;
    if(fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    str = malloc(sizeof(char) * BUFFER_SIZE);
    j = read(fd, str, BUFFER_SIZE);
    while(str[0], str[i] != '\n')
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


int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        int fd = open(argv[1], O_RDONLY);
        char *str = get_next_line(fd);
        printf("%s", str);
        printf("%s", get_next_line(fd));
    }

}