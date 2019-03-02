/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lld.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 22:27:53 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:13:45 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "libft.h"

void		print_llld(long long n)
{
	if (n == -9223372036854775807 - 1)
	{
		write(1, "9223372036854775808", 19);
		return ;
	}
	if (n < 0)
		n *= -1;
	if (n > 9)
		print_llld(n / 10);
	ft_putchar(n % 10 + 48);
}

static int	geti(int n)
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

int			print_lld(va_list ap, t_flags elem)
{
	long long	n;
	int			i;

	i = 1;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = va_arg(ap, long long);
	if (n == -9223372036854775807 - 1)
		i = 20;
	else
		i += geti(n);
	return (n == 0 && elem.accuracy == 0 ?
	padding_d(n, 0, elem) : i +
	padding_d(n, i, elem));
}
