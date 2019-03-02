/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:27:01 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 20:58:48 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_hu(va_list ap, t_flags elem)
{
	unsigned short	n;
	unsigned short	cp;
	int				i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = (unsigned short)va_arg(ap, unsigned int);
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
