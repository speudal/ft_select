/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 23:26:49 by tduval            #+#    #+#             */
/*   Updated: 2019/03/11 01:44:08 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H

# include <termcap.h>
# include <termios.h>

# define ESC		"\x1b"
# define UP_ARROW	"\x1b[A"
# define UP_DOWN	"\x1b[B"
# define UP_RIGHT	"\x1b[C"
# define UP_LEFT	"\x1b[D"

typedef enum		e_bool
{
	false,
	true
}					t_bool;

typedef struct		s_args
{
	char			*arg;
	t_bool			head;
	t_bool			cur;
	t_bool			selected;
	struct s_args	*prev;
	struct s_args	*next;
}					t_args;

int					ft_select(int ac, char **av);

#endif
