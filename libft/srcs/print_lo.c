/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:14:51 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:14:21 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		print_lo(va_list ap, t_flags elem)
{
	unsigned long	n;
	unsigned long	cp;
	int				i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = va_arg(ap, unsigned long);
	cp = n;
	if (ft_strchr(elem.options, '#'))
		i++;
	if (ft_strchr(elem.options, '#') && !n)
		return ((int)write(1, "0", 1));
	while (cp > 7)
	{
		cp /= 8;
		i++;
	}
	return (n == 0 && elem.accuracy == 0 ?
	padding_o((unsigned long long)n, 0, elem) : i +
	padding_o((unsigned long long)n, i, elem));
}
