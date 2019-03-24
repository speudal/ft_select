/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sighandler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 17:00:04 by tduval            #+#    #+#             */
/*   Updated: 2019/03/24 19:30:53 by tduval           ###   ########.fr       */
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
	(void)a;
	reset_term();
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
    signal(SIGINT, SIG_DFL);
    signal(SIGHUP, SIG_DFL);
    signal(SIGQUIT, SIG_DFL);
    signal(SIGABRT, SIG_DFL);
    signal(SIGWINCH, SIG_DFL);
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
	exit(a);
}

void		sighandler(void)
{
	signal(SIGTSTP, sigtstp_case);
	signal(SIGCONT, sigcont_case);
	signal(SIGTERM, exit_properly);
	signal(SIGINT, exit_properly);
	signal(SIGHUP, exit_properly);
	signal(SIGQUIT, exit_properly);
	signal(SIGABRT, exit_properly);
	signal(SIGWINCH, sigwinch_case);
}
