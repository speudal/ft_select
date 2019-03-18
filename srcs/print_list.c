/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 16:58:30 by tduval            #+#    #+#             */
/*   Updated: 2019/03/18 18:47:39 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"

extern t_args	*g_lst;

static int	num_lins()
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
	ft_putnbr(i);
	return (i);
}

void	print_list(void)
{
	int		col;
	int		lin;
	char	*tc;

	tc = tgetstr("cl", 0);
	tputs(tc, 1, ft_putchar);
	col = tgetnum("co");
	lin = tgetnum("li");
	ft_putnbr(col);
	if (lin < num_lins())
		ft_putendl("error");
	else
		print_all();
}
