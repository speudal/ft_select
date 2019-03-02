/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:55:49 by tduval            #+#    #+#             */
/*   Updated: 2018/11/07 20:31:57 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	int		j;

	i = 0;
	j = -1;
	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	while (s[i])
	{
		if (s[i] == c)
			j = i;
		i++;
	}
	return (j != -1 ? (char *)(s + j) : 0);
}
