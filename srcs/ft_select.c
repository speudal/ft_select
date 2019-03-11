/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:56:26 by tduval            #+#    #+#             */
/*   Updated: 2019/03/11 02:01:47 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

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
			ret->cur = true;
			ret->head = true;
			origin = ret;
		}
		else
		{
			if (!(ret->next = new_arg(av[i])))
				return (0);
			ret->next->prev = ret;
			ret->next->cur = false;
			ret->next->head = false;
			ret = ret->next;
		}
		i++;
	}
	ret->next = origin;
	return (origin);
}

static void	print_all(t_args *list)
{
	if (list)
	{
		if (list->selected == true)
			ft_putstr("\e[7m");
		ft_putstr(list->arg);
		ft_putstr("\e[0m");
		list = list->next;
	}
	while (list && list->head == false)
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
	char	*tc;
	int		c;
	char	buf[4];

	if (ac < 2 || !(selected = init_selec(ac, av)))
		return (0);
	while ((c = read(0, buf, 3)) && ft_strcmp(buf, ESC))
	{
		buf[c] = 0;
		tc = tgetstr("cl", 0);
		tputs(tc, 0, ft_putchar);
		print_all(selected);
		tc = tgetstr("ho", 0);
		tputs(tc, 0, ft_putchar);
		tc = tgetstr("hu", 0);
		tputs(tc, 0, ft_putchar);
		ft_putchar('\n');
	}
	return (0);
}
