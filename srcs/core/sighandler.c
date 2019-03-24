/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:00:04 by tduval            #+#    #+#             */
/*   Updated: 2019/03/24 20:22:23 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include "ft_select.h"
#include "libft.h"

extern t_args	*g_lst;

static void	sigwinch_case(int a)
{
	(void)a;
	print_list();
}

static void	sigtstp_case(int a)
{
	int		i;

	i = 1;
	(void)a;
	reset_term();
	while (i < 32)
	{
		if (i != 9 && i != SIGCONT)
			signal(i, SIG_DFL);
		i++;
	}
	ioctl(2, TIOCSTI, "\x1A");
}

static void	sigcont_case(int a)
{
	(void)a;
	init_term();
	print_list();
	signal(SIGCONT, SIG_DFL);
	sighandler();
}

void		exit_properly(int a)
{
	(void)a;
	free_list();
	reset_term();
	exit(1);
}

void		sighandler(void)
{
	int		i;

	i = 1;
	while (i < 32)
	{
		if (i != 9)
			signal(i, exit_properly);
		i++;
	}
	signal(SIGTSTP, sigtstp_case);
	signal(SIGCONT, sigcont_case);
	signal(SIGWINCH, sigwinch_case);
}
