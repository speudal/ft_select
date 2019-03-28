/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:23:32 by tduval            #+#    #+#             */
/*   Updated: 2019/03/28 19:54:40 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"
#include "libft.h"

extern t_args	*g_lst;

static void	print_padding(char *str, int e)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	while (i < e)
	{
		ft_putchar_fd(' ', 2);
		i++;
	}
}

static void	ft_printcur(t_args *g_lst, int pec[3])
{
	if (g_lst->cur == true)
		ft_putstr_fd("\e[4m", 2);
	if (g_lst->selected == true)
		ft_putstr_fd("\e[7m", 2);
	ft_putstr_fd(g_lst->arg, 2);
	ft_putstr_fd("\e[0m", 2);
	if (pec[0] && pec[2] && (pec[0] % pec[2] == 0))
		ft_putchar_fd('\n', 2);
	else
		print_padding(g_lst->arg, pec[1]);
}

void		print_all(void)
{
	int		pec[3];
	int		i;

	i = 1;
	deter_col(pec);
	pec[0] = 1;
	while (g_lst->head == false)
		g_lst = g_lst->next;
	while ((g_lst && g_lst->head == false) || i)
	{
		ft_printcur(g_lst, pec);
		g_lst = g_lst->next;
		pec[0]++;
		i = 0;
	}
}
