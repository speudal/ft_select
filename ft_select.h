/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tduval <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 23:26:49 by tduval            #+#    #+#             */
/*   Updated: 2019/05/09 13:31:57 by tduval           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H

# define UP_ARROW		"\x1b[A"
# define DOWN_ARROW		"\x1b[B"
# define RIGHT_ARROW	"\x1b[C"
# define LEFT_ARROW		"\x1b[D"
# define DELETE			"\x1b[3~"

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

void				deter_col(int pec[3]);
void				print_all(void);
void				print_list(void);
void				exit_properly(int a);
void				sighandler(void);
void				init_term(void);
void				free_list(void);
void				reset_term(void);
int					main(int ac, char **av);
int					up_case(void);
int					down_case(void);
int					ft_select(int ac, char **av);
int					inter_keys(char buf[5]);

#endif
