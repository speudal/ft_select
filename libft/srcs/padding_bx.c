/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_bx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 22:14:23 by tduval            #+#    #+#             */
/*   Updated: 2018/12/02 16:54:42 by tduval           ###   ########.fr       */
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
			ft_putstr("0X");
		while (elem.accuracy-- > s - (ft_strchr(elem.options, '#') &&
				n ? 2 : 0))
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
		print_lllbx(n);
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
	int		q;
	int		i;

	i = 0;
	q = ft_strchr(elem.options, '#') ? 2 : 0;
	while (elem.width-- > s + (elem.accuracy > s ? elem.accuracy - s + q : 0))
	{
		ft_putchar(ft_strchr(elem.options, '0') &&
					elem.accuracy == -1 ? '0' : ' ');
		i++;
	}
	return (i);
}

int			padding_bx(unsigned long long n, int s, t_flags elem)
{
	int i;
	int	w;
	int u;

	i = 0;
	w = elem.width;
	if (ft_strchr(elem.options, '#') && elem.accuracy == -1 &&
			(elem.width < s || ft_strchr(elem.options, '0')) && n)
		ft_putstr("0X");
	if (!ft_strchr(elem.options, '-') && elem.width)
		i += split3(s, elem);
	u = elem.accuracy;
	if (ft_strchr(elem.options, '#') && elem.accuracy == -1 && n
		&& w > s && !ft_strchr(elem.options, '0'))
		ft_putstr("0X");
	return (i + split2(n, s, u, elem));
}
