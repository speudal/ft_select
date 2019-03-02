/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hhd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:40:42 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:12:15 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	geti(char n)
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

int			print_hhd(va_list ap, t_flags elem)
{
	char	n;
	int		i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = (char)va_arg(ap, int);
	if (n == -128)
		i = 4;
	else
		i += geti(n);
	return (n == 0 && elem.accuracy == 0 ?
	padding_d((long long)n, 0, elem) : i +
	padding_d((long long)n, i, elem));
}
