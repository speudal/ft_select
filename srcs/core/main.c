/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:11:08 by tduval            #+#    #+#             */
/*   Updated: 2019/03/21 18:14:26 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_select.h"

void		init_term(char *term_type, int ac, char **av)
{
	struct termios	term;
	int				ret;

	if ((ret = tgetent(0, term_type)) == -1)
	{
		ft_putstr_fd("Couldn't access to database.\n", 2);
		return ;
	}
	else if (ret == 0)
	{
		ft_putendl_fd("Terminal undefined in termcap database.", 2);
		return ;
	}
	tcgetattr(2, &term);
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(2, TCSADRAIN, &term);
	ret = ft_select(ac, av);
}

int				main(int ac, char **av)
{
	char	*term_type;

	if (ac > 1)
	{
		if (!(term_type = getenv("TERM")))
		{
			ft_putstr_fd("ERROR: TERM variable not set.\n", 2);
			return (-1);
		}
		init_term(term_type, ac, av);
	}
	else
		ft_putendl_fd("ft_select: usage: ft_select [arg1] [arg2] ...", 2);
	return (0);
}
