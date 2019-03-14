/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 18:19:22 by tduval            #+#    #+#             */
/*   Updated: 2019/03/14 23:20:04 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_select.h"

static int	up_case(t_args *lst)
{
	while (lst && lst->cur != true)
		lst = lst->next;
	if (lst->prev && lst->prev != lst)
	{
		lst->prev->cur = true;
		lst->cur = false;
	}
	return (0);
}

static int	down_case(t_args *lst)
{
	while (lst && lst->cur != true)
		lst = lst->next;
	if (lst->next && lst->next != lst)
	{
		lst->next->cur = true;
		lst->cur = false;
	}
	return (0);
}

static int	del_case(t_args *lst)
{
	t_args	*tmp;

	if (lst && lst->next == lst)
		return (1);
	while (lst && lst->next && lst->next->cur != true)
		lst = lst->next;
	if (lst->next->head == true)
		lst->next->next->head = true;
	tmp = lst->next;
	lst->next = lst->next->next;
	lst->next->cur = true;
	free(tmp->arg);
	free(tmp);
	return (0);
}

static int	space_case(t_args *lst)
{
	while (lst && lst->cur == false)
		lst = lst->next;
	lst->selected = (lst->selected ? false : true);
	lst->cur = false;
	lst->next->cur = true;
	return (0);
}

int		inter_keys(char buf[5], t_args *lst)
{

	if (ft_strequ(UP_ARROW, buf))
		return (up_case(lst));
	if (ft_strequ(DOWN_ARROW, buf))
		return (down_case(lst));
	if (ft_strequ(DELETE, buf) || ft_strequ(BACKSPACE, buf))
		return (del_case(lst));
	if (buf[0] == ' ')
		return (space_case(lst));
	return (0);
}
