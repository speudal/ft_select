# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 23:21:58 by tduval            #+#    #+#              #
#    Updated: 2019/01/14 21:42:41 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_select

CC			=	clang

CFLAGS		=	-Wall -Werror -Wextra

SRCS		=	srcs/main.c

INCLUDES	=	-I . -I libft/

LIBFT		=	libft/libft.a

OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBFT) -o $(NAME) -ltermcap
	@echo "\x1b[36m[FT_SELECT COMPILED]\x1b[0m"

%.o : %.c
	@gcc -c $(CFLAGS) $(INCLUDES) $< -o $@

$(LIBFT) :
	@$(MAKE) -C libft/

clean :
	@$(MAKE) -C libft/ clean
	@echo "\x1b[33;01mft_select : cleaning...\x1b[0m"
	@rm -f $(OBJS)
	@echo "\x1b[32;01m[FT_SELECT CLEANED]\x1b[0m"

fclean : clean
	@$(MAKE) -C libft/ fclean
	@echo "\x1b[33;01mft_select : fcleaning...\x1b[0m"
	@rm -f $(NAME)
	@echo "\x1b[32;01m[FT_SELECT FCLEANED]\x1b[0m"

re : fclean all

.PHONY : all clean fclean re
