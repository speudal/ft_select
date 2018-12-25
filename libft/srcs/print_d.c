/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:30:13 by tduval            #+#    #+#             */
/*   Updated: 2018/12/14 21:58:36 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	geti(int n)
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

int			print_d(va_list ap, t_flags elem)
{
	int	i;
	int	n;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = va_arg(ap, int);
	if (n == -2147483648)
		i = 11;
	else
		i += geti(n);
	return (n == 0 && elem.accuracy == 0 ?
			padding_d((long long)n, 0, elem) : i +
			padding_d((long long)n, i, elem));
}
