/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 09:34:13 by tduval            #+#    #+#             */
/*   Updated: 2018/11/09 17:01:48 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	ft_power(int pow)
{
	int	rep;

	rep = 1;
	while (pow > 0)
	{
		rep *= 10;
		pow--;
	}
	return (rep);
}

static int	ft_count_char(int n)
{
	int	ct;

	ct = (n > -1 ? 1 : 2);
	n = (n > -1 ? n : -n);
	while (n > 9)
	{
		n /= 10;
		ct++;
	}
	return (ct);
}

char		*ft_itoa(int n)
{
	int		i;
	int		a;
	char	*num;

	a = n > -1 ? ft_count_char(n) : ft_count_char(-n);
	i = 0;
	if (!(num = (char *)malloc(sizeof(char) * (ft_count_char(n) + 1))))
		return (0);
	if (n == -2147483648)
		return (ft_strcpy(num, "-2147483648"));
	if (n < 0)
	{
		num[i] = '-';
		n *= -1;
		i++;
	}
	while (i < (num[0] == '-' ? ft_count_char(n) + 1 : ft_count_char(n)))
	{
		num[i] = n / ft_power(a - 1) % 10 + 48;
		a--;
		i++;
	}
	num[i] = '\0';
	return (num);
}
