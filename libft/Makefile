# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tduval <tduval@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 13:08:51 by tduval            #+#    #+#              #
#    Updated: 2018/12/12 13:38:10 by tduval           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

CFLAGS	=	-Wall -Werror -Wextra -I.

SRCS	=	./srcs/dispatcher.c		\
			./srcs/fill_flags.c		\
			./srcs/ft_abs.c			\
			./srcs/ft_atoi.c		\
			./srcs/ft_bzero.c		\
			./srcs/ft_factorial.c	\
			./srcs/ft_isalnum.c		\
			./srcs/ft_isalpha.c		\
			./srcs/ft_isascii.c		\
			./srcs/ft_isdigit.c		\
			./srcs/ft_isprint.c		\
			./srcs/ft_itoa.c		\
			./srcs/ft_lstadd.c		\
			./srcs/ft_lstdel.c		\
			./srcs/ft_lstdelone.c	\
			./srcs/ft_lstiter.c		\
			./srcs/ft_lstmap.c		\
			./srcs/ft_lstnew.c		\
			./srcs/ft_memalloc.c	\
			./srcs/ft_memccpy.c		\
			./srcs/ft_memchr.c		\
			./srcs/ft_memcmp.c		\
			./srcs/ft_memcpy.c		\
			./srcs/ft_memdel.c		\
			./srcs/ft_memmove.c		\
			./srcs/ft_memset.c		\
			./srcs/ft_printf.c		\
			./srcs/ft_putchar.c		\
			./srcs/ft_putchar_fd.c	\
			./srcs/ft_putendl.c		\
			./srcs/ft_putendl_fd.c	\
			./srcs/ft_putnbr.c		\
			./srcs/ft_putnbr_fd.c	\
			./srcs/ft_putstr.c		\
			./srcs/ft_putstr_fd.c	\
			./srcs/ft_sort.c		\
			./srcs/ft_sqrt.c		\
			./srcs/ft_strcat.c		\
			./srcs/ft_strchr.c		\
			./srcs/ft_strclr.c		\
			./srcs/ft_strcmp.c		\
			./srcs/ft_strcpy.c		\
			./srcs/ft_strdel.c		\
			./srcs/ft_strdup.c		\
			./srcs/ft_strequ.c		\
			./srcs/ft_striter.c		\
			./srcs/ft_striteri.c	\
			./srcs/ft_strjoin.c		\
			./srcs/ft_strfjoin.c	\
			./srcs/ft_strlcat.c		\
			./srcs/ft_strlen.c		\
			./srcs/ft_strmap.c		\
			./srcs/ft_strmapi.c		\
			./srcs/ft_strncat.c		\
			./srcs/ft_strncmp.c		\
			./srcs/ft_strncpy.c		\
			./srcs/ft_strnequ.c		\
			./srcs/ft_strnew.c		\
			./srcs/ft_strnstr.c		\
			./srcs/ft_strrchr.c		\
			./srcs/ft_strsplit.c	\
			./srcs/ft_strstr.c		\
			./srcs/ft_strsub.c		\
			./srcs/ft_strtrim.c		\
			./srcs/ft_sum.c			\
			./srcs/ft_swap.c		\
			./srcs/ft_tolower.c		\
			./srcs/ft_toupper.c		\
			./srcs/get_next_line.c	\
			./srcs/get_flags.c		\
			./srcs/padding_bx.c		\
			./srcs/padding_d.c		\
			./srcs/padding_o.c		\
			./srcs/padding_sx.c		\
			./srcs/padding_u.c		\
			./srcs/print_bx.c		\
			./srcs/print_c.c		\
			./srcs/print_d.c		\
			./srcs/print_hbx.c		\
			./srcs/print_hd.c		\
			./srcs/print_hhbx.c		\
			./srcs/print_hhd.c		\
			./srcs/print_hhi.c		\
			./srcs/print_hho.c		\
			./srcs/print_hhsx.c		\
			./srcs/print_hhu.c		\
			./srcs/print_hi.c		\
			./srcs/print_ho.c		\
			./srcs/print_hsx.c		\
			./srcs/print_hu.c		\
			./srcs/print_i.c		\
			./srcs/print_lbx.c		\
			./srcs/print_ld.c		\
			./srcs/print_li.c		\
			./srcs/print_llbx.c		\
			./srcs/print_lld.c		\
			./srcs/print_lli.c		\
			./srcs/print_llo.c		\
			./srcs/print_llsx.c		\
			./srcs/print_llu.c		\
			./srcs/print_lo.c		\
			./srcs/print_lsx.c		\
			./srcs/print_lu.c		\
			./srcs/print_o.c		\
			./srcs/print_p.c		\
			./srcs/print_per.c		\
			./srcs/print_s.c		\
			./srcs/print_sx.c		\
			./srcs/print_u.c

OBJS =	$(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "\x1b[36m[LIBFT COMPILED]\x1b[0m"

clean :
	@rm -f $(OBJS)
	@echo "\x1b[33;01mlibft : cleaning...\x1b[0m"
	@echo "\x1b[32;01m[LIBFT CLEANED]\x1b[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\x1b[33;01mlibft : fcleaning...\x1b[0m"
	@echo "\x1b[32;01m[LIBFT FCLEANED]\x1b[0m"

%.o : %.c
	@gcc -c $(CFLAGS) $< -o $@

re : fclean all

.PHONY : all clean fclean re
