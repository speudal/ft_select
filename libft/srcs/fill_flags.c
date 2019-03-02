/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <tduval@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 16:28:48 by tduval            #+#    #+#             */
/*   Updated: 2018/12/12 21:11:22 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		field_n(char c, int field)
{
	if (field == 0)
		return (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0');
	if (field == 1)
		return (c == 'h' || c == 'l' || c == 'L' || c == 'j' || c == 'z');
	return (0);
}

static t_flags	errors_flags(t_flags elem)
{
	elem.wrong = 1;
	return (elem);
}

static t_flags	split_fill(const char *str, int *i, t_flags elem)
{
	int	j;

	j = 0;
	while (field_n(str[*i], 0) && str[*i])
	{
		if (!ft_strchr(elem.options, str[*i]))
		{
			elem.options[j] = str[*i];
			j++;
		}
		(*i)++;
	}
	elem.width = ft_atoi(str + *i);
	if (str[*i] == '*')
		elem.width = -1;
	while ((str[*i] == '*' || ft_isdigit(str[*i])) && str[*i])
		(*i)++;
	if (str[*i] == '.')
	{
		(*i)++;
		elem.accuracy = ft_atoi(str + *i);
	}
	return (elem);
}

static t_flags	split_fifi(const char *str, int *i, t_flags elem)
{
	int		j;

	j = 0;
	while (ft_isdigit(str[*i]) && str[*i])
		(*i)++;
	while (field_n(str[*i], 1) && str[*i])
	{
		elem.size[j] = str[*i];
		(*i)++;
		j++;
	}
	return (elem);
}

t_flags			fill_flags(const char *str)
{
	t_flags elem;
	int		i;

	i = 0;
	elem.accuracy = -1;
	elem.wrong = 0;
	elem.width = 0;
	elem.conv = 0;
	elem.options = 0;
	elem.size = 0;
	if (!(elem.options = ft_strnew(6)))
		return (errors_flags(elem));
	if (!(elem.size = ft_strnew(3)))
		return (errors_flags(elem));
	elem = split_fill(str, &i, elem);
	elem = split_fifi(str, &i, elem);
	if (str[i])
		elem.conv = str[i];
	return (elem);
}
