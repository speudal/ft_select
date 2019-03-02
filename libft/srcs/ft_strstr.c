/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 04:39:49 by tduval            #+#    #+#             */
/*   Updated: 2018/11/08 00:42:51 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*tmp;

	while (*haystack)
	{
		tmp = needle;
		while (*haystack && *tmp && *haystack == *tmp)
		{
			haystack++;
			tmp++;
		}
		if (*tmp == '\0')
			return ((char *)(haystack - ft_strlen(needle)));
		else
			haystack -= tmp - needle;
		if (*haystack == '\0')
			return (0);
		haystack++;
	}
	return (ft_strlen(needle) ? 0 : (char *)haystack);
}
