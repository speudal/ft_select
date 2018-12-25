/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_llu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 23:35:55 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:14:11 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_lllu(unsigned long long n)
{
	if (n > 9)
		print_lllu(n / 10);
	ft_putchar(n % 10 + 48);
}

int		print_llu(va_list ap, t_flags elem)
{
	unsigned long long	n;
	unsigned long long	cp;
	int					i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = va_arg(ap, unsigned long long);
	cp = n;
	while (cp > 9)
	{
		cp /= 10;
		i++;
	}
	return (n == 0 && elem.accuracy == 0 ?
	padding_u(n, 0, elem) : i +
	padding_u(n, i, elem));
}
