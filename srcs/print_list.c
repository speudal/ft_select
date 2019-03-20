/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:58:30 by tduval            #+#    #+#             */
/*   Updated: 2019/03/20 15:30:53 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/ioctl.h>
#include "libft.h"
#include "ft_select.h"

extern t_args	*g_lst;

static int	num_lins(void)
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
	return (i + 2);
}

void		print_list(void)
{
	struct winsize	si;
	char	*tc;

	tc = tgetstr("cl", 0);
	tputs(tc, 0, ft_putchar);
	ioctl(0, TIOCGWINSZ, &si);
	if (si.ws_row < num_lins())
		ft_putendl_fd("ERROR: PLEASE RESIZE THE WINDOW.\n", 2);
	else
		print_all();
}
