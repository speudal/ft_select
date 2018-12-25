/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 17:41:22 by tduval            #+#    #+#             */
/*   Updated: 2018/12/11 17:42:46 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	free_both(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
}

char	*ft_strfjoin(char *s1, char *s2)
{
	char	*s;
	char	*res;

	if (!s1 || !s2)
		return (0);
	if (!(s = (char *)malloc(sizeof(char) * \
		(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	res = s;
	while (*s1)
	{
		*s = *s1;
		s++;
		s1++;
	}
	while (*s2)
	{
		*s = *s2;
		s++;
		s2++;
	}
	*s = '\0';
	free_both(s1, s2);
	return (res);
}
