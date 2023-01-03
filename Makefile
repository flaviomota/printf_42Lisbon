# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/05 10:52:41 by fmota             #+#    #+#              #
#    Updated: 2021/03/05 10:52:41 by fmota            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
HEADER = ft_printf.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS =	ft_printf.c analyzers.c establish_int.c establish_str.c ft_aux.c \
		render_int.c render_lowhex.c render_str.c render_unsigned.c \
		render_uphex.c route.c set_flags.c utils.c

OBJS = $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

bonus: 		all

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean:		
		rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re 