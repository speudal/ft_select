/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:56:26 by tduval            #+#    #+#             */
/*   Updated: 2019/03/11 23:08:25 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

static void		sigint_handler(int sig)
{
	sig = 0;
	ft_putstr("rip");
}

static void		sig_handler(void)
{
	signal(SIGINT, sigint_handler);
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
	origin->prev = ret;
	return (origin);
}

static void	print_all(t_args *list)
{
	if (list)
	{
		if (list->cur == true)
			ft_putstr("\e[4m");
		if (list->selected == true)
			ft_putstr("\e[7m");
		ft_putstr(list->arg);
		ft_putstr("\e[0m");
		list = list->next;
	}
	while (list && list->head == false)
	{
		ft_putchar('\t');
		if (list->cur == true)
			ft_putstr("\e[4m");
		if (list->selected == true)
			ft_putstr("\e[7m");
		ft_putstr(list->arg);
		ft_putstr("\e[0m");
		list = list->next;
	}
}

void		use_arr(char buf[5], t_args *lst)
{
	t_args	*tmp;

	if (ft_strequ(LEFT_ARROW, buf))
	{
		while (lst && lst->cur != true)
			lst = lst->next;
		if (lst->prev)
			lst->prev->cur = true;
		lst->cur = false;
	}
	if (ft_strequ(RIGHT_ARROW, buf))
	{
		while (lst && lst->cur != true)
			lst = lst->next;
		if (lst->next)
			lst->next->cur = true;
		lst->cur = false;
	}
	if (ft_strequ(DELETE, buf))
	{
		while (lst && lst->next && lst->next->cur != true)
			lst = lst->next;
		if (lst->next->head == true)
			lst->next->next->head = true;
		tmp = lst->next;
		lst->next = lst->next->next;
		lst->next->cur = true;
		free(tmp->arg);
		free(tmp);
	}
	if (buf[0] == ' ')
	{
		while (lst && lst->cur != true)
			lst = lst->next;
		lst->selected = (lst->selected ? false : true);
		lst->cur = false;
		lst->next->cur = true;
	}
}

int				ft_select(int ac, char **av)
{
	t_args	*selected;
	char	*tc;
	int		c;
	char	buf[5];

	sig_handler();
	if (ac < 2 || !(selected = init_selec(ac, av)))
		return (0);
	print_all(selected);
	while ((c = read(0, buf, 4)) && ft_strcmp(buf, ESC))
	{
		buf[c] = 0;
		use_arr(buf, selected);
		tc = tgetstr("cl", 0);
		tputs(tc, 0, ft_putchar);
		print_all(selected);
		ft_putchar('\n');
	}
	return (0);
}
