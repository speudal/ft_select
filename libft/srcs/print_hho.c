/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hho.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:12:56 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 20:55:36 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		print_hho(va_list ap, t_flags elem)
{
	unsigned char	n;
	unsigned char	cp;
	int				i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = (unsigned char)va_arg(ap, int);
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
	padding_o(n, 0, elem) : i +
	padding_o(n, i, elem));
}
