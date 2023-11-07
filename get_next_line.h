/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:50:55 by diegmore          #+#    #+#             */
/*   Updated: 2023/11/07 14:32:28 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

char	*get_next_line(int fd);
char	*ft_strdup(char *src);
char *ft_finder(char *str, char c);
int	ft_strlen(char *str);

#endif

