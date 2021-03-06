# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 23:21:58 by tduval            #+#    #+#              #
#    Updated: 2019/03/24 20:39:07 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_select

CC			=	gcc

HEADER		=	./ft_select.h

CFLAGS		=	-Wall -Werror -Wextra -g

SRCS		=	srcs/core/main.c		\
				srcs/core/sighandler.c	\
				srcs/core/reset_term.c	\
				srcs/core/ft_select.c	\
				srcs/keys/inter_keys.c	\
				srcs/keys/updown_keys.c	\
				srcs/print/print_list.c	\
				srcs/print/print_all.c	\
				srcs/tools/free_list.c	\
				srcs/tools/init_term.c	\
				srcs/calcs/deter_col.c

CPPFLAGS	=	-I . -I libft/

LIBFT		=	libft/libft.a

OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) $(CPPFLAGS) $(LIBFT) -o $(NAME) -ltermcap
	@echo "\x1b[36m<=========== FT_SELECT COMPILED ===========>\x1b[0m"

%.o : %.c
	@printf "\x1b[33;01mPre-compiling : \x1b[0m"
	@echo $<
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@

$(LIBFT) :
	@$(MAKE) -C libft/

clean :
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJS)
	@echo "\x1b[32;01m<=========== FT_SELECT CLEANED ===========>\x1b[0m"

fclean : clean
	@$(MAKE) -C libft/ fclean
	@rm -f $(NAME)
	@echo "\x1b[32;01m<========== FT_SELECT FCLEANED ===========>\x1b[0m"

re : fclean all

.PHONY : all clean fclean re
