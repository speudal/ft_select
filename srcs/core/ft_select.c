/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:56:26 by tduval            #+#    #+#             */
/*   Updated: 2019/03/21 18:13:50 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

t_args	*g_lst = 0;

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
	ret->head = false;
	ret->selected = false;
	ret->cur = false;
	ret->next = 0;
	return (ret);
}

static t_args	*init_selec(int ac, char **av)
{
	t_args	*origin;
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (g_lst == 0)
		{
			if (!(g_lst = new_arg(av[i])))
				return (0);
			g_lst->cur = true;
			g_lst->head = true;
			origin = g_lst;
		}
		else
		{
			if (!(g_lst->next = new_arg(av[i])))
				return (0);
			g_lst->next->prev = g_lst;
			g_lst = g_lst->next;
		}
	}
	g_lst->next = origin;
	origin->prev = g_lst;
	return (origin);
}

static void		print_selec(void)
{
	int		i;

	i = 0;
	while (g_lst->head == false)
		g_lst = g_lst->next;
	if (g_lst->selected == true)
	{
		ft_putstr(g_lst->arg);
		i = 1;
	}
	g_lst = g_lst->next;
	while (g_lst && g_lst->head == false)
	{
		if (g_lst->selected == true)
		{
			if (i)
				ft_putchar(' ');
			ft_putstr(g_lst->arg);
			i = 1;
		}
		g_lst = g_lst->next;
	}
}

static int		end_game(void)
{
	char	*tc;
	t_args	*tmp;

	while (g_lst->prev->head == false)
		g_lst = g_lst->next;
	while (g_lst && g_lst->head == false)
	{
		tmp = g_lst;
		free(tmp->arg);
		free(tmp);
		g_lst = g_lst->next;
	}
	free(g_lst);
	free(g_lst->arg);
	tc = tgetstr("ve", 0);
	tputs(tc, 2, ft_putchar);
	return (0);
}

int				ft_select(int ac, char **av)
{
	char	*tc;
	int		c;
	char	buf[5];

	sighandler();
	if (ac < 2 || (!g_lst && !(init_selec(ac, av))))
		return (0);
	print_list();
	while ((c = read(0, buf, 4))
			&& ft_strcmp(buf, ESC) && ft_strcmp(buf, RETURN))
	{
		buf[c] = 0;
		inter_keys(buf);
		tc = tgetstr("cl", 0);
		tputs(tc, 2, ft_putchar);
		tc = tgetstr("ti", 0);
		tputs(tc, 2, ft_putchar);
		print_list();
		ft_bzero(buf, c);
		ft_putchar('\n');
	}
	if (ft_strequ(buf, RETURN))
		print_selec();
	return (end_game());
}
