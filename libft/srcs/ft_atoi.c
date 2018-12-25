/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/26 18:54:13 by tduval            #+#    #+#             */
/*   Updated: 2018/12/02 19:34:22 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long	res;
	int			neg;
	int			i;

	i = -1;
	res = 0;
	while (str[++i] == 32 || (str[i] > 8 && str[i] < 14))
		;
	neg = (str[i] == '-' ? 1 : 0);
	i += (str[i] == '+' || str[i] == '-' ? 1 : 0);
	while (ft_isdigit(str[i]))
	{
		res += str[i] - 48;
		res *= (ft_isdigit((str[i + 1])) ? 10 : 1);
		++i;
	}
	return (neg == 1 ? (int)-res : (int)res);
}
