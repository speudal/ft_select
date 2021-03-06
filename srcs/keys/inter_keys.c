/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:19:22 by tduval            #+#    #+#             */
/*   Updated: 2019/05/09 14:12:59 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termcap.h"
#include "libft.h"
#include "ft_select.h"

extern	t_args	*g_lst;

static int	left_case(void)
{
	while (g_lst && g_lst->cur != true)
		g_lst = g_lst->next;
	if (g_lst->prev && g_lst->prev != g_lst)
	{
		g_lst->prev->cur = true;
		g_lst->cur = false;
	}
	return (0);
}

static int	right_case(void)
{
	while (g_lst && g_lst->cur != true)
		g_lst = g_lst->next;
	if (g_lst->next && g_lst->next != g_lst)
	{
		g_lst->next->cur = true;
		g_lst->cur = false;
	}
	return (0);
}

static int	del_case(void)
{
	t_args	*pr;
	t_args	*ne;

	if (g_lst && g_lst->next == g_lst)
		exit_properly(42);
	while (g_lst->cur == false)
		g_lst = g_lst->next;
	if (g_lst->head == true)
		g_lst->next->head = true;
	pr = g_lst->prev;
	ne = g_lst->next;
	pr->next = ne;
	ne->cur = true;
	ne->prev = pr;
	ft_strdel(&(g_lst->arg));
	ft_memdel((void **)&g_lst);
	g_lst = pr;
	return (0);
}

static int	space_case(void)
{
	while (g_lst && g_lst->cur == false)
		g_lst = g_lst->next;
	g_lst->selected = (g_lst->selected ? false : true);
	g_lst->cur = false;
	g_lst->next->cur = true;
	return (0);
}

int			inter_keys(char buf[4])
{
	if (ft_strequ(tgetstr("ku", 0), buf))
		return (up_case());
	if (ft_strequ(tgetstr("kd", 0), buf))
		return (down_case());
	if (ft_strequ(tgetstr("kl", 0), buf))
		return (left_case());
	if (ft_strequ(tgetstr("kr", 0), buf))
		return (right_case());
	if (buf[0] == 127 || ft_strequ(buf, tgetstr("kD", 0)))
		return (del_case());
	if (buf[0] == ' ')
		return (space_case());
	return (0);
}
