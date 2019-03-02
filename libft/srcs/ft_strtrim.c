/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:13:59 by tduval            #+#    #+#             */
/*   Updated: 2018/11/09 17:07:17 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	ft_is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char			*ft_strtrim(char const *s)
{
	int	i;
	int	j;

	if (!s)
		return (0);
	i = 0;
	j = 0;
	while (ft_is_space(s[i]))
		i++;
	j = ft_strlen(s);
	while (ft_is_space(s[j - 1]) && j > i)
		j--;
	return (ft_strsub(s, i, (j - i)));
}
