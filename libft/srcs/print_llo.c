/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_llo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:08:31 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:13:55 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	print_lllo(unsigned long long n)
{
	if (n > 7)
		print_lllo(n / 8);
	ft_putchar(n % 8 + 48);
}

int		print_llo(va_list ap, t_flags elem)
{
	unsigned long long	n;
	unsigned long long	cp;
	int					i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = va_arg(ap, unsigned long long);
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
