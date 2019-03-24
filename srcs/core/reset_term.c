/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:31:06 by tduval            #+#    #+#             */
/*   Updated: 2019/03/23 19:57:42 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"

extern struct termios	g_rep;

void	reset_term(void)
{
	tputs(tgetstr("ve", 0), 2, ft_putchar);
	tcsetattr(2, TCSANOW, &g_rep);
}
