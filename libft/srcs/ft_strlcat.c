/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:02:24 by tduval            #+#    #+#             */
/*   Updated: 2018/11/12 17:51:36 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dst[j] && j < size)
		j++;
	while (src[i] && (j + i + 1) < size)
	{
		dst[i + j] = src[i];
		i++;
	}
	if (j < size)
		dst[i + j] = '\0';
	return (j + ft_strlen(src));
}
