/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:31:12 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:14:37 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_lu(va_list ap, t_flags elem)
{
	unsigned long	n;
	unsigned long	cp;
	int				i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = va_arg(ap, unsigned long);
	cp = n;
	while (cp > 9)
	{
		cp /= 10;
		i++;
	}
	return (n == 0 && elem.accuracy == 0 ?
	padding_u((unsigned long long)n, 0, elem) : i +
	padding_u((unsigned long long)n, i, elem));
}
