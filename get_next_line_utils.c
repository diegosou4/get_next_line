/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:53:23 by diegmore          #+#    #+#             */
/*   Updated: 2023/11/06 10:43:32 by diemorei         ###   ########.fr       */
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
	free(src);
	return (dest);
}

char *ft_finder(char *str, char c)
{
	int i;
	i = 0;
	char *strr;
	int j;
	j = 0;

	while(str[i] != c || str[i] != '\0')
	{
		i++;
	}
	i++;
	strr = (char *)calloc(sizeof(char) , (i + 1));
	if(!strr)
		return (NULL);
	while(j != i)
	{
		strr[j] = str[j];
		j++;;
	}
	return (strr);
}
