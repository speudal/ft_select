/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:11:08 by tduval            #+#    #+#             */
/*   Updated: 2019/03/24 19:40:44 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_select.h"

static int		check_term(char *term_type)
{
	int				ret;

	if ((ret = tgetent(0, term_type)) == -1 || tgetstr("cl", 0) == 0)
	{
		ft_putstr_fd("Couldn't access to database.\n", 2);
		return (-1);
	}
	else if (ret == 0)
	{
		ft_putendl_fd("Terminal undefined in termcap database.", 2);
		return (-1);
	}
	return (0);
}

int				main(int ac, char **av)
{
	char	*term_type;

	if (ac > 1)
	{
		if (!(term_type = getenv("TERM")) || check_term(term_type) == -1)
		{
			if (!(term_type))
				ft_putstr_fd("ERROR: TERM variable not set.\n", 2);
			return (-1);
		}
		init_term();
		ft_select(ac, av);
	}
	else
		ft_putendl_fd("ft_select: usage: ft_select [arg1] [arg2] ...", 2);
	return (0);
}
