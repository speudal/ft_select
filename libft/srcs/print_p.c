/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 21:56:10 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:14:52 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

static void	print(size_t n)
{
	if (n > 15)
		print(n / 16);
	ft_putchar(n % 16 > 9 ? n % 16 + 'a' - 10 : n % 16 + '0');
}

static int	count(size_t n, int u, t_flags elem)
{
	int	i;

	i = 0;
	while (n > 15)
	{
		n /= 16;
		u++;
		i++;
	}
	while (elem.width > u && !(ft_strchr(elem.options, '-')))
	{
		ft_putchar(' ');
		u++;
		i++;
	}
	return (i);
}

int			print_p(va_list ap, t_flags elem)
{
	size_t		n;
	int			i;

	i = 3;
	if (elem.width == -1)
		elem.width = va_arg(ap, int);
	n = va_arg(ap, size_t);
	if (!n && !elem.accuracy)
		return ((int)(write(1, "0x", 2)));
	i += count(n, i, elem);
	ft_putstr("0x");
	while (elem.accuracy > i - 2)
	{
		ft_putchar('0');
		i++;
	}
	print(n);
	while (elem.width > i && ft_strchr(elem.options, '-'))
	{
		ft_putchar(' ');
		i++;
	}
	return (i);
}
