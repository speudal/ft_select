/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:50:53 by tduval            #+#    #+#             */
/*   Updated: 2019/03/22 19:27:17 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_select.h"

extern t_args	*g_lst;

void			free_list(void)
{
	t_args	*tmp;

	if (g_lst)
	{
		while (g_lst->prev->head == false)
			g_lst = g_lst->next;
		while (g_lst && g_lst->next && g_lst->head == false)
		{
			tmp = g_lst;
			g_lst = g_lst->next;
			free(tmp->arg);
			free(tmp);
		}
	}
}
