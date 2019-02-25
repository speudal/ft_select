/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:11:08 by tduval            #+#    #+#             */
/*   Updated: 2019/01/14 21:55:55 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "ft_select.h"

static int		init_term(char *term_type)
{
	int	ret;

	if ((ret = tgetent(0, term_type)) == -1)
	{
		ft_putstr("Couldn't access to database.\n");
		return (-1);
	}
	else if (ret == 0)
	{
		 ft_putstr("Terminal undefined in termcap database (or have too few informations).\n");	
		 return (-1);
	}
	return (ret);
}

int				main(void)
{
	int		ret;
	int		col;
	int		lin;
	char	*tc;
	char	*term_type;

	if (!(term_type = getenv("TERM")))
	{
		ft_putstr("ERROR: TERM variable not set.\n");
		return (-1);
	}
	if ((ret = init_term(term_type)))
	{
		col = tgetnum("co");
		lin = tgetnum("li");
		ft_printf("col = %d | lin = %d\n", col, lin);
		tc = tgetstr("cl", 0);
		tputs(tc, 1, ft_putchar);
	}
	return (0);
}
