/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 22:58:32 by tduval            #+#    #+#             */
/*   Updated: 2018/11/30 22:59:04 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split3(int s, t_flags elem)
{
	int i;

	i = 0;
	if (elem.accuracy != -1)
	{
		if (ft_strchr(elem.options, '+'))
		{
			ft_putchar('+');
			i++;
		}
		while (elem.accuracy-- > s)
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

	i = split3(s, elem);
	if (n || (!n && elem.accuracy != 0))
		print_lllu(n);
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

int			padding_u(unsigned long long n, int s, t_flags elem)
{
	int i;
	int u;

	i = 0;
	if (!ft_strchr(elem.options, '-') && elem.width)
	{
		while (elem.width > s + ((((ft_strchr(elem.options, ' ') ||
								ft_strchr(elem.options, '+')) &&
							n > 0)
						? 1
						: 0) +
					(elem.accuracy > s ? elem.accuracy - s : 0)))
		{
			ft_putchar(ft_strchr(elem.options, '0') &&
					elem.accuracy == -1
					? '0'
					: ' ');
			elem.width--;
			i++;
		}
	}
	u = elem.accuracy;
	return (i + split2(n, s, u, elem));
}
