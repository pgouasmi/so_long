# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pgouasmi <pgouasmi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/07 18:35:15 by pgouasmi          #+#    #+#              #
#    Updated: 2023/04/16 18:54:01 by pgouasmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCSLIB = ./includes/libft/ft_isalnum.c	\
		./includes/libft/ft_isalpha.c		\
		./includes/libft/ft_isascii.c		\
		./includes/libft/ft_isdigit.c		\
		./includes/libft/ft_isprint.c		\
		./includes/libft/ft_itoa.c		\
		./includes/libft/ft_strchr.c		\
		./includes/libft/ft_strdup.c		\
		./includes/libft/ft_strjoin.c		\
		./includes/libft/ft_strlcat.c		\
		./includes/libft/ft_strlcpy.c		\
		./includes/libft/ft_strlen.c		\
		./includes/libft/ft_strncmp.c		\
		./includes/libft/ft_strnstr.c		\
		./includes/libft/ft_strrchr.c		\
		./includes/libft/ft_strtrim.c		\
		./includes/libft/ft_substr.c		\
		./includes/libft/ft_tolower.c		\
		./includes/libft/ft_toupper.c		\
		./includes/libft/ft_atoi.c		\
		./includes/libft/ft_itoa.c		\
		./includes/libft/ft_split.c 		\
		./includes/libft/ft_strtrim.c		\
		./includes/libft/ft_substr.c		\
		./includes/libft/ft_bzero.c		\
		./includes/libft/ft_memcpy.c		\
		./includes/libft/ft_memmove.c		\
		./includes/libft/ft_memset.c		\
		./includes/libft/ft_strmapi.c		\
		./includes/libft/ft_striteri.c	\
		./includes/libft/ft_calloc.c		\
		./includes/libft/ft_memcmp.c		\
		./includes/libft/ft_memchr.c		\
		./includes/libft/ft_putchar_fd.c	\
		./includes/libft/ft_putstr_fd.c	\
		./includes/libft/ft_putnbr_fd.c	\
		./includes/libft/ft_putendl_fd.c	\
		./includes/libft/ft_lstadd_front.c	\
		./includes/libft/ft_lstlast.c		\
		./includes/libft/ft_lstnew.c		\
		./includes/libft/ft_lstsize.c		\
		./includes/ft_printf/ft_printf.c		\
		./includes/ft_printf/ft_putchar_pf.c	\
		./includes/ft_printf/ft_putnbr_base.c	\
		./includes/ft_printf/ft_putnbr_base_p.c\
		./includes/ft_printf/ft_putstr_pf.c	\
		./includes/GNL/get_next_line.c		\
		./includes/GNL/get_next_line_bonus.c		\
		./includes/GNL/get_next_line_utils.c		\
		./includes/GNL/get_next_line_utils_bonus.c		\
		./includes/push_swap/push_swap.c				\
		./includes/push_swap/instructions_ps/instructions_push_swap.c	\
		./includes/push_swap/instructions_ps/instructions_push_swap2.c	\
		./includes/push_swap/instructions_ps/instructions_push_swap3.c	\
		./includes/push_swap/push_swap_resources/argv_manager1.c			\
		./includes/push_swap/push_swap_resources/argv_manager2.c			\
		./includes/push_swap/push_swap_resources/push_swap_tools.c			\
		./includes/push_swap/push_swap_resources/radix_tools.c				\
		./includes/push_swap/push_swap_resources/radix_index_tools.c		\
		./includes/push_swap/push_swap_algorithms/push_swap_algorithms.c 	\
		./includes/push_swap/push_swap_algorithms/two_elements_case.c		\
		./includes/push_swap/push_swap_algorithms/three_elements_case.c	\
		./includes/push_swap/push_swap_algorithms/radix_sort.c	\
		

OBJS = ${SRCSLIB:.c=.o}
HEADER = libft.h
CC = cc
FLAG = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER) Makefile
			ar -rcs $(NAME) $(OBJS)

%.o:	%.c $(HEADER) Makefile
			$(CC) $(FLAG) -I . -c $< -o $@

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

ffclean:	fclean
			rm -f ./a.out

re :
	make fclean
	make

remake :	re
			$(CC) $(FLAG) so_long.c libft.a
		