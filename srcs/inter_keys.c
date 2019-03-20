/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:19:22 by tduval            #+#    #+#             */
/*   Updated: 2019/03/20 17:17:49 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_select.h"

extern	t_args	*g_lst;

static int	up_case(void)
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

static int	down_case(void)
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
	t_args	*tmp;

	if (g_lst && g_lst->next == g_lst)
		exit_properly(42);
	while (g_lst && g_lst->next && g_lst->next->cur != true)
		g_lst = g_lst->next;
	if (g_lst->next->head == true)
		g_lst->next->next->head = true;
	tmp = g_lst->next;
	g_lst->next = g_lst->next->next;
	g_lst->next->cur = true;
	ft_strdel(&(tmp->arg));
	ft_memdel((void **)&tmp);
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

int		inter_keys(char buf[5])
{
	if (ft_strequ(UP_ARROW, buf))
		return (up_case());
	if (ft_strequ(DOWN_ARROW, buf))
		return (down_case());
	if (ft_strequ(DELETE, buf) || ft_strequ(BACKSPACE, buf))
		return (del_case());
	if (buf[0] == ' ')
		return (space_case());
	return (0);
}
