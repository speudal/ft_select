/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_per.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 23:12:15 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:09:39 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int		print_per(t_flags elem)
{
	char	c;
	int		i;
	int		j;

	i = 0;
	while (i < elem.width - 1 && !ft_strchr(elem.options, '-'))
	{
		ft_putchar(ft_strchr(elem.options, '0') ? '0' : ' ');
		i++;
	}
	c = '%';
	i += (int)write(1, &c, 1);
	j = 0;
	while (j < elem.width - 1 && ft_strchr(elem.options, '-'))
	{
		ft_putchar(' ');
		i++;
		j++;
	}
	return (i);
}
