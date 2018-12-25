/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 19:07:16 by tduval            #+#    #+#             */
/*   Updated: 2018/12/11 18:23:21 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	split1(int s, long long n, t_flags elem, int *j)
{
	int		i;

	i = 0;
	if (n > -1)
	{
		if (ft_strchr(elem.options, '+') && elem.accuracy == -1 && n > -1 &&
			(elem.width < s || ft_strchr(elem.options, '0')))
		{
			ft_putchar('+');
			*j = 1;
			i++;
		}
		else if (ft_strchr(elem.options, ' ') && !ft_strchr(elem.options, '+')
					&& n > -1)
		{
			ft_putchar(' ');
			*j = 1;
			i++;
		}
	}
	else if (elem.accuracy == -1 && ft_strchr(elem.options, '0') && n < 0)
		ft_putchar('-');
	return (i);
}

static int	split3(long long n, int s, t_flags elem)
{
	int	i;

	i = 0;
	if (elem.accuracy != -1)
	{
		if (n < 0)
			ft_putchar('-');
		else if (ft_strchr(elem.options, '+'))
		{
			ft_putchar('+');
			i++;
		}
		while (elem.accuracy-- > s - (n < 0 ? 1 : 0))
		{
			ft_putchar('0');
			i++;
		}
	}
	return (i);
}

static int	split2(long long n, int s, int u, t_flags elem)
{
	int	i;

	i = split3(n, s, elem);
	if (!ft_strchr(elem.options, '0') && elem.accuracy == -1 && n < 0)
		ft_putchar('-');
	if (ft_strchr(elem.options, '+') && !ft_strchr(elem.options, '0') &&
		elem.width >= s && elem.accuracy == -1 && n > -1)
	{
		ft_putchar('+');
		i++;
	}
	if (n || (!n && elem.accuracy != 0))
		print_llld((long long)n);
	if (ft_strchr(elem.options, '-'))
	{
		while (elem.width > s + ((((ft_strchr(elem.options, ' ') ||
				ft_strchr(elem.options, '+')) && n > -1) ? 1 : 0) ||
					(n < 0 && elem.accuracy > s - 1 ? 1 : 0)) +
					(u != -1 && u > s ? u - s : 0) && i++)
		{
			ft_putchar(' ');
			elem.width--;
		}
	}
	return (i);
}

int			padding_d(long long n, int s, t_flags elem)
{
	int	i;
	int	u;
	int	j;

	i = split1(s, n, elem, &j);
	if (!ft_strchr(elem.options, '-') && elem.width)
	{
		while (elem.width > s + ((((ft_strchr(elem.options, ' ') ||
				ft_strchr(elem.options, '+')) && n > -1) || (n < 0
				&& elem.accuracy > s - 1) ? 1 : 0) +
				(elem.accuracy > s ? elem.accuracy - s : 0)))
		{
			ft_putchar(ft_strchr(elem.options, '0') &&
						elem.accuracy == -1 ? '0' : ' ');
			elem.width--;
			i++;
		}
	}
	u = elem.accuracy;
	return (i + split2(n, s, u, elem));
}
