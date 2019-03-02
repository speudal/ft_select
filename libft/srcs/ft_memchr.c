/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 17:24:36 by tduval            #+#    #+#             */
/*   Updated: 2018/11/09 16:23:50 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*cpy;

	i = 0;
	cpy = (unsigned char *)s;
	while (n--)
	{
		if (cpy[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}
