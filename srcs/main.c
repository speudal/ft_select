/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:11:08 by tduval            #+#    #+#             */
/*   Updated: 2019/03/13 19:43:25 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_select.h"

static int		init_term(char *term_type)
{
	struct termios	term;
	int	ret;

	if ((ret = tgetent(0, term_type)) == -1)
	{
		ft_putstr_fd("Couldn't access to database.\n", 2);
		return (-1);
	}
	else if (ret == 0)
	{
		 ft_putstr_fd("Terminal undefined in termcap database (or have too few informations).\n", 2);	
		 return (-1);
	}
	tcgetattr(0, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSADRAIN, &term);
	return (ret);
}

int				main(int ac, char **av)
{
	int		ret;
	char	*tc;
	char	*term_type;

	if (ac > 1)
	{
		if (!(term_type = getenv("TERM")))
		{
			ft_putstr_fd("ERROR: TERM variable not set.\n", 2);
			return (-1);
		}
		if ((ret = init_term(term_type)))
		{
			tc = tgetstr("cl", 0);
			tputs(tc, 1, ft_putchar);
			tc = tgetstr("vi", 0);
			tputs(tc, 1, ft_putchar);
			ft_select(ac, av);
			tc = tgetstr("ve", 0);
			tputs(tc, 1, ft_putchar);
		}
	}
	return (0);
}
