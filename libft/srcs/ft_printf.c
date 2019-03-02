/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:40:53 by tduval            #+#    #+#             */
/*   Updated: 2018/12/02 17:04:30 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void	free_whole(t_flags *list, int ct)
{
	int		i;

	i = 0;
	while (i < ct)
	{
		ft_memdel((void **)&(list[i].options));
		ft_memdel((void **)&(list[i].size));
		i++;
	}
	if (list)
		free(list);
}

static int	sub2(const char *format)
{
	if (format[0] && format[0] == '%')
		return (0);
	else
		return ((int)write(1, format, ft_strlen(format)));
}

static void	split(int res[4], va_list ap, t_flags *list, const char *format)
{
	if (check_sizes(list[res[1]].size, list[res[1]].conv))
	{
		if (list[res[1]].conv == '%')
		{
			res[0] += dispatcher(list[res[1]], ap);
			res[2]++;
			while (format[res[2]] != '%')
				res[2]++;
		}
		else
		{
			res[0] += dispatcher(list[res[1]], ap);
			while (!ft_strchr("cdfiopsuxXDOU", format[res[2]])
					&& format[res[2]])
				res[2]++;
		}
	}
	res[2]++;
	res[1]++;
}

static void	split2(const char *format, t_flags *list, va_list ap, int res[4])
{
	if (format[res[2]] == '%')
		split(res, ap, list, format);
	else
	{
		res[0]++;
		ft_putchar(format[res[2]]);
		res[2]++;
	}
}

int			ft_printf(const char *format, ...)
{
	t_flags	*list;
	va_list	ap;
	int		res[4];

	list = 0;
	res[0] = 0;
	res[1] = 0;
	res[2] = 0;
	res[3] = 0;
	if (ft_strlen(format) < 2)
		return (sub2(format));
	va_start(ap, format);
	if (!(list = get_flags(format, &(res[3]))))
	{
		free_whole(list, res[3]);
		return (-1);
	}
	while (format[res[2]])
		split2(format, list, ap, res);
	free_whole(list, res[3]);
	va_end(ap);
	return (res[0]);
}
