/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hhu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:29:23 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 20:57:28 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		print_hhu(va_list ap, t_flags elem)
{
	unsigned char	n;
	unsigned char	cp;
	int				i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = (unsigned char)va_arg(ap, int);
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
