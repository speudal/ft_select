/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:29:20 by tduval            #+#    #+#             */
/*   Updated: 2019/03/28 19:53:59 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

extern t_args	*g_lst;

static int	number_args(void)
{
	int		i;

	i = 1;
	while (g_lst->head == false)
		g_lst = g_lst->next;
	while (g_lst->next && g_lst->next->head == false)
	{
		g_lst = g_lst->next;
		i++;
	}
	return (i);
}

int			down_case(void)
{
	int		i;
	int		pec[3];

	pec[0] = number_args();
	deter_col(pec);
	i = 0;
	while (g_lst->cur == false)
		g_lst = g_lst->next;
	g_lst->cur = false;
	while (i < pec[2] && g_lst->next->head == false)
	{
		g_lst = g_lst->next;
		i++;
	}
	g_lst->cur = true;
	return (0);
}

int			up_case(void)
{
	int		pec[3];
	int		i;

	pec[0] = number_args();
	deter_col(pec);
	i = 0;
	while (g_lst->cur == false)
		g_lst = g_lst->next;
	g_lst->cur = false;
	while (i < pec[2] && g_lst->head == false)
	{
		g_lst = g_lst->prev;
		i++;
	}
	g_lst->cur = true;
	return (0);
}
