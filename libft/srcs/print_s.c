/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:45:30 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:09:46 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static int	split(t_flags elem, int j, char *s)
{
	int		i;

	i = 0;
	while (elem.width && elem.width - i > j && !(ft_strchr(elem.options, '-')))
	{
		ft_putchar(ft_strchr(elem.options, '0') ? '0' : ' ');
		i++;
	}
	j = 0;
	if ((int)ft_strlen(s) > elem.accuracy && elem.accuracy != -1)
	{
		while (j < elem.accuracy && s[j])
		{
			ft_putchar(s[j]);
			i++;
			j++;
		}
	}
	else
		i += (int)write(1, s, ft_strlen((char *)s));
	return (i);
}

int			print_s(va_list ap, t_flags elem)
{
	char		*s;
	int			i;
	int			j;

	i = 0;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	s = va_arg(ap, char *);
	if (!s)
	{
		free(s);
		s = "(null)";
	}
	j = ((int)ft_strlen(s) > elem.accuracy && elem.accuracy != -1) ?
		elem.accuracy : (int)ft_strlen(s);
	i += split(elem, j, s);
	while (elem.width && elem.width > j && ft_strchr(elem.options, '-'))
	{
		ft_putchar(' ');
		elem.width--;
		i++;
	}
	return (i);
}
