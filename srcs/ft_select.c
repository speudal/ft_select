/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 23:56:26 by tduval            #+#    #+#             */
/*   Updated: 2019/03/14 18:31:01 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_select.h"
#include "libft.h"

static void		sign_handler(int sig)
{
	char	*tc;
	(void)sig;

	tc = tgetstr("ve", 0);
	tputs(tc, 0, ft_putchar);
	exit(0);
}

static void		sig_handler(void)
{
	signal(1, sign_handler);
	signal(2, sign_handler);
	signal(3, sign_handler);
	signal(4, sign_handler);
	signal(5, sign_handler);
	signal(6, sign_handler);
	signal(7, sign_handler);
	signal(8, sign_handler);
	signal(9, sign_handler);
	signal(10, sign_handler);
	signal(11, sign_handler);
	signal(12, sign_handler);
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
	ret->selected = false;
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
			ft_putstr_fd("\e[4m", 2);
		if (list->selected == true)
			ft_putstr_fd("\e[7m", 2);
		ft_putendl_fd(list->arg, 2);
		ft_putstr_fd("\e[0m", 2);
		list = list->next;
	}
	while (list && list->head == false)
	{
		if (list->cur == true)
			ft_putstr_fd("\e[4m", 2);
		if (list->selected == true)
			ft_putstr_fd("\e[7m", 2);
		ft_putendl_fd(list->arg, 2);
		ft_putstr_fd("\e[0m", 2);
		list = list->next;
	}
}

void			print_selec(t_args *lst)
{
	int		i;

	i = 0;
	while (lst->head == false)
		lst = lst->next;
	if (lst->selected == true)
	{
		ft_putstr(lst->arg);
		i = 1;
	}
	lst = lst->next;
	while (lst && lst->head == false)
	{
		if (lst->selected == true)
		{
			if (i)
				ft_putchar(' ');
			ft_putstr(lst->arg);
			i = 1;
		}
		lst = lst->next;
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
	while ((c = read(0, buf, 4)) && ft_strcmp(buf, ESC) && ft_strcmp(buf, RETURN))
	{
		buf[c] = 0;
		inter_keys(buf, selected);
		tc = tgetstr("cl", 0);
		tputs(tc, 0, ft_putchar);
		print_all(selected);
		ft_putchar('\n');
	}
	if (ft_strequ(buf, RETURN))
		print_selec(selected);
	return (0);
}
