/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diemorei <diemorei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:53:23 by diegmore          #+#    #+#             */
/*   Updated: 2023/11/07 14:32:24 by diemorei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




char	*ft_strdup(char *src)
{
	char	*dest;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen((char *)src);
	dest = (char *)malloc((size + 1)* sizeof(char));
	if (!dest)
	{
		free(dest);
		return (NULL);
	}
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

