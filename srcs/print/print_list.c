/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:58:30 by tduval            #+#    #+#             */
/*   Updated: 2019/03/20 21:00:38 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "libft.h"
#include "ft_select.h"

extern t_args	*g_lst;

static int	largest_one(void)
{
	size_t	i;

	while (g_lst && g_lst->head == false)
		g_lst = g_lst->next;
	i = ft_strlen(g_lst->arg);
	while (g_lst->next->head == false)
	{
		if (i < ft_strlen(g_lst->arg))
			i = ft_strlen(g_lst->arg);
		g_lst = g_lst->next;
	}
	return ((int)i);
}

static int	num_lins(int pec[3])
{
	int		i;

	i = 0;
	while (g_lst && g_lst->head == false)
		g_lst = g_lst->next;
	while (g_lst && g_lst->next->head == false)
	{
		g_lst = g_lst->next;
		i++;
	}
	return ((i + i % pec[2]) / (pec[2]));
}

void		print_list(void)
{
	struct winsize	si;
	int				pec[3];
	char			*tc;

	tc = tgetstr("cl", 0);
	tputs(tc, 2, ft_putchar);
	deter_col(pec);
	if (ioctl(2, TIOCGWINSZ, &si) != -1)
	{
		if (pec[2] == 0
				|| si.ws_row < num_lins(pec)
				|| si.ws_col < largest_one() + 2)
			ft_putendl_fd("ERROR: PLEASE RESIZE THE WINDOW.\n", 2);
		else
			print_all();
	}
}
