/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_sx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 23:00:35 by tduval            #+#    #+#             */
/*   Updated: 2018/11/30 23:04:05 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split1(unsigned long long n, int s, t_flags elem)
{
	int i;

	i = 0;
	if (elem.accuracy != -1)
	{
		if (ft_strchr(elem.options, '#') && n)
			ft_putstr("0x");
		while (elem.accuracy-- > s - (ft_strchr(elem.options, '#')
				&& n ? 2 : 0))
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}

static int	split2(unsigned long long n, int s, int u, t_flags elem)
{
	int i;

	i = split1(n, s, elem);
	if (n || (!n && elem.accuracy != 0))
		print_lllsx((unsigned long long)n);
	if (ft_strchr(elem.options, '-') && elem.width)
	{
		while (elem.width > s + ((ft_strchr(elem.options, ' ') ||
				ft_strchr(elem.options, '+')) ? 1 : 0) + (u != -1 ? u - s : 0))
		{
			ft_putchar(' ');
			elem.width--;
			i++;
		}
	}
	return (i);
}

static int	split3(int s, t_flags elem)
{
	int		i;
	int		j;

	i = 0;
	j = ft_strchr(elem.options, '#') ? 2 : 0;
	while (elem.width > s + (elem.accuracy > s ? elem.accuracy - s +
			j : 0))
	{
		ft_putchar(ft_strchr(elem.options, '0') &&
					elem.accuracy == -1 ? '0' : ' ');
		elem.width--;
		i++;
	}
	return (i);
}

int			padding_sx(unsigned long long n, int s, t_flags elem)
{
	int i;
	int	w;
	int u;

	i = 0;
	w = elem.width;
	if (ft_strchr(elem.options, '#') && elem.accuracy == -1 &&
		(elem.width < s || ft_strchr(elem.options, '0')) && n)
		ft_putstr("0x");
	if (!ft_strchr(elem.options, '-') && elem.width)
		i += split3(s, elem);
	u = elem.accuracy;
	if (ft_strchr(elem.options, '#') && elem.accuracy == -1 && n
		&& w > s && !ft_strchr(elem.options, '0'))
		ft_putstr("0x");
	return (i + split2(n, s, u, elem));
}
