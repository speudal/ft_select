/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 03:55:30 by tduval            #+#    #+#             */
/*   Updated: 2018/11/09 17:03:31 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*src1;
	char	*dst1;

	src1 = (char *)src;
	dst1 = (char *)dst;
	if (src == dst)
		return (dst);
	if (src < dst)
	{
		while (len--)
			dst1[len] = src1[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
