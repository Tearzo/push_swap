# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavorapa <pavorapa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/30 21:54:35 by pavorapa          #+#    #+#              #
#    Updated: 2025/01/30 22:15:15 by pavorapa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINTF = ft_printf.c ft_putchar.c ft_puthex.c ft_putnbr_unsigned.c ft_putnbr.c ft_putstr.c ft_putptr.c

SRCS = ${PRINTF}

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	ar -rsc ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
