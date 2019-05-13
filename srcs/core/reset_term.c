/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_term.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:31:06 by tduval            #+#    #+#             */
/*   Updated: 2019/05/13 13:38:34 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <termcap.h>
#include <termios.h>
#include "libft.h"

extern struct termios	g_rep;

void	reset_term()
{
	ft_putstr_fd("\033[?1049l", 2);
	tputs(tgetstr("ke", 0), 2, ft_putchar);
	tputs(tgetstr("ve", 0), 2, ft_putchar);
	tcsetattr(2, TCSANOW, &g_rep);
}
