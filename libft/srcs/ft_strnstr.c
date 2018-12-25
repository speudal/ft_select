/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:45:10 by tduval            #+#    #+#             */
/*   Updated: 2018/11/08 04:17:03 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (*haystack == '\0' || !len)
		return (0);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && len-- >= ft_strlen(needle))
	{
		if (!ft_strncmp(haystack, needle, ft_strlen(needle)))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
