/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_o.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:47:48 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:14:43 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		print_o(va_list ap, t_flags elem)
{
	unsigned int	n;
	unsigned int	cp;
	int				i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = va_arg(ap, unsigned int);
	if (ft_strchr(elem.options, '#') && (elem.width < 1 || n))
		i++;
	if (ft_strchr(elem.options, '#') && !n && elem.width < 1)
		return ((int)write(1, "0", 1));
	cp = n;
	while (cp > 7)
	{
		cp /= 8;
		i++;
	}
	return (n == 0 && elem.accuracy == 0 ?
	padding_o((unsigned long long)n, 0, elem) : i +
	padding_o((unsigned long long)n, i, elem));
}
