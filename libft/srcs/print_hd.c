/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:37:35 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:04:24 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	geti(short n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int			print_hd(va_list ap, t_flags elem)
{
	short	n;
	int		i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = (short)va_arg(ap, int);
	if (n == -32768)
		i = 6;
	else
		i += geti(n);
	return (n == 0 && elem.accuracy == 0 ?
	padding_d((long long)n, 0, elem) : i +
	padding_d((long long)n, i, elem));
}
