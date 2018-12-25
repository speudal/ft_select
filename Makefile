# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/25 23:21:58 by tduval            #+#    #+#              #
#    Updated: 2018/12/25 23:29:05 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_select

CFLAGS		=	-Wall -Werror -Wextra

SRCS		=	srcs/ft_select.c

INCLUDES	=	-I . -I libft/

LIBFT		=	libft/libft.a

OBJS		=	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	gcc -c $(CFLAGS) $(INCLUDES) $< -o $@

$(LIBFT) :
	$(MAKE) -C libft/

clean :
	$(MAKE) -C libft/ clean
	rm -f $(OBJS)

fclean : clean
	$(MAKE) -C libft/ fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all
