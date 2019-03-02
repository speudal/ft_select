/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:56:26 by tduval            #+#    #+#             */
/*   Updated: 2019/02/26 00:50:24 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

static void		del_key(char *key)
{
	size_t	i;
	char	*tc;

	i = 0;
	tc = tgetstr("dc", 0);
	while (i < ft_strlen(key))
	{
		tputs(tc, 1, ft_putchar);
		i++;
	}
}

static t_args	*new_arg(char *arg)
{
	t_args	*ret;

	if (!(ret = (t_args *)ft_memalloc(sizeof(t_args))))
		return (0);
	if (!(ret->arg = ft_strdup(arg)))
	{
		free(ret);
		return (0);
	}
	ret->selected = 0;
	ret->next = 0;
	return (ret);
}

static t_args	*init_selec(int ac, char **av)
{
	t_args	*ret;
	t_args	*origin;
	int		i;

	i = 1;
	ret = 0;
	origin = 0;
	while (i < ac)
	{
		if (ret == 0)
		{
			if (!(ret = new_arg(av[i])))
				return (0);
			origin = ret;
		}
		else
		{
			if (!(ret->next = new_arg(av[i])))
				return (0);
			ret = ret->next;
		}
		i++;
	}
	return (origin);
}

static void	print_all(t_args *list)
{
	while (list)
	{
		if (list->selected == true)
			ft_putstr("\e[7m");
		ft_putstr(list->arg);
		ft_putstr("\e[0m");
		list = list->next;
		if (list)
			ft_putchar('\t');
	}
}

int				ft_select(int ac, char **av)
{
	t_args	*selected;
	int		c;
	char	buf[3];

	if (ac < 2 || !(selected = init_selec(ac, av)))
		return (0);
	while ((c = read(0, buf, 2)) && ft_strcmp(buf, ESC))
	{
		buf[c] = 0;
		del_key(buf);
		print_all(selected);
		ft_putchar('\n');
	}
	return (0);
}
