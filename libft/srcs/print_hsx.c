/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hsx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 10:35:52 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 20:58:22 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		print_hsx(va_list ap, t_flags elem)
{
	unsigned short	n;
	unsigned short	cp;
	int				i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = (unsigned short)va_arg(ap, unsigned int);
	cp = n;
	if (ft_strchr(elem.options, '#') && (elem.width < 1 || n))
		if (elem.accuracy || n || (elem.width > 1 && !n))
			i += 2;
	if (ft_strchr(elem.options, '#') && !n && elem.width < 1 &&
			elem.accuracy == -1)
		return ((int)write(1, "0", 1));
	while (cp > 15)
	{
		cp /= 16;
		i++;
	}
	return (n == 0 && elem.accuracy == 0 ?
	padding_sx((unsigned long long)n, 0, elem) : i +
	padding_sx((unsigned long long)n, i, elem));
}
