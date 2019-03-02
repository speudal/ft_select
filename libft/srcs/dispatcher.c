/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 00:17:46 by tduval            #+#    #+#             */
/*   Updated: 2018/12/02 16:50:58 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	(*g_array_print[60])(va_list ap, t_flags elem) = {
	print_c,
	print_c,
	print_c,
	print_c,
	print_c,
	print_s,
	print_s,
	print_s,
	print_s,
	print_s,
	print_p,
	print_p,
	print_p,
	print_p,
	print_p,
	print_d,
	print_hd,
	print_hhd,
	print_ld,
	print_lld,
	print_i,
	print_hi,
	print_hhi,
	print_li,
	print_lli,
	print_o,
	print_ho,
	print_hho,
	print_lo,
	print_llo,
	print_u,
	print_hu,
	print_hhu,
	print_lu,
	print_llu,
	print_sx,
	print_hsx,
	print_hhsx,
	print_lsx,
	print_llsx,
	print_bx,
	print_hbx,
	print_hhbx,
	print_lbx,
	print_llbx,
	print_ld,
	print_ld,
	print_ld,
	print_ld,
	print_ld,
	print_lo,
	print_lo,
	print_lo,
	print_lo,
	print_lo,
	print_lu,
	print_lu,
	print_lu,
	print_lu,
	print_lu
};

int			check_sizes(char *str, char conv)
{
	return (ft_strchr("cspdiouxXDOU%", conv) &&
			((!ft_strcmp(str, "h") || !ft_strcmp(str, "hh") ||
				!ft_strcmp(str, "l") || !ft_strcmp(str, "ll") ||
				!ft_strcmp(str, "") || !ft_strcmp(str, "z") ||
				!ft_strcmp(str, "j"))));
}

static int	split_dispatcher(va_list ap, t_flags elem, int *i)
{
	if (!check_sizes(elem.size, elem.conv))
		return (0);
	if (!(ft_strcmp(elem.size, "h")) && elem.conv != '%')
		(*i)++;
	if (!(ft_strcmp(elem.size, "hh")) && elem.conv != '%')
		*i += 2;
	if (!(ft_strcmp(elem.size, "l")) && elem.conv != '%')
		*i += 3;
	if ((!(ft_strcmp(elem.size, "ll")) ||
		!(ft_strcmp(elem.size, "j"))) && elem.conv != '%')
		*i += 4;
	if ((!(ft_strcmp(elem.size, "z")) &&
		(elem.conv == 'd' || elem.conv == 'i')))
		return (print_lld(ap, elem));
	if ((!(ft_strcmp(elem.size, "z")) && elem.conv == 'u'))
		return (print_llu(ap, elem));
	if ((!(ft_strcmp(elem.size, "z")) && elem.conv == 'o'))
		return (print_llo(ap, elem));
	if ((!(ft_strcmp(elem.size, "z")) && elem.conv == 'x'))
		return (print_llsx(ap, elem));
	if ((!(ft_strcmp(elem.size, "z")) && elem.conv == 'X'))
		return (print_llbx(ap, elem));
	if (elem.conv == '%')
		return (print_per(elem));
	return (0);
}

int			dispatcher(t_flags elem, va_list ap)
{
	int		i;
	int		j;
	char	*flags;

	i = 0;
	if (!elem.conv)
		return (0);
	flags = "cspdiouxXDOU";
	while (flags[i] != elem.conv && flags[i])
		i++;
	i %= 13;
	i *= 5;
	j = split_dispatcher(ap, elem, &i);
	if (j)
		return (j);
	return (i < 60 ? g_array_print[i](ap, elem) : 0);
}
