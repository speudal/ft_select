/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:24:55 by tduval            #+#    #+#             */
/*   Updated: 2018/12/02 17:05:03 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_flags	*split_get(int *t, t_flags *list, const char *str)
{
	int	p;
	int	i;

	p = 0;
	(*t) = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%' && !p)
		{
			i++;
			if ((list[*t] = fill_flags(str + i)).wrong)
				return (0);
			if (list[*t].conv == '%' && str[i] != '%')
				p = 1;
			(*t)++;
		}
		else if (str[i] == '%' && p)
			p = 0;
	}
	return (list);
}

t_flags			*get_flags(const char *str, int *t)
{
	t_flags *list;
	int		ct;
	int		i;

	ct = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '%')
			ct++;
	if (!(list = (t_flags *)malloc(sizeof(t_flags) * (ct + 1))))
		return (0);
	return (split_get(t, list, str));
}
