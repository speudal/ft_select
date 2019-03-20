/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deter_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:15:10 by tduval            #+#    #+#             */
/*   Updated: 2019/03/20 17:55:27 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "ft_select.h"
#include "libft.h"

extern t_args	*g_lst;

void	deter_col(int pec[3])
{
	struct winsize	win;
	size_t			i;

	while (g_lst->head == false)
		g_lst = g_lst->next;
	i = ft_strlen(g_lst->arg);
	g_lst = g_lst->next;
	while (g_lst->head == false)
	{
		if (ft_strlen(g_lst->arg) > i)
			i = ft_strlen(g_lst->arg);
		g_lst = g_lst->next;
	}
	ioctl(2, TIOCGWINSZ, &win);
	pec[1] = i + 1;
	pec[2] = ((int)(win.ws_col / i));
}
