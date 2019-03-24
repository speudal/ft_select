/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 18:08:10 by tduval            #+#    #+#             */
/*   Updated: 2019/03/23 19:58:03 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_select.h"

struct termios	g_rep;

void			init_term(void)
{
	struct termios	term;

	tcgetattr(2, &term);
	g_rep = term;
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(2, TCSADRAIN, &term);
	tputs(tgetstr("cl", 0), 2, ft_putchar);
	tputs(tgetstr("vi", 0), 2, ft_putchar);
}
