# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpetit <tpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/29 16:26:58 by tpetit            #+#    #+#              #
#    Updated: 2020/09/30 10:53:58 by tpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c ft_putstr.c ft_atoi.c ft_putstr.c find_square.c ft_putnbr.c ft_puterr.c constructors.c read_std_in.c other_functions.c print_result.c
SRCS = ${addprefix srcs/, ${SRC}}
OBJS = ${SRCS:.c=.o}
CC = gcc
FLAGS = -Wall -Wextra -Werror
NAME = BSQ

all : ${NAME}

allup : all clean

grid :
	bash make_grid/make_grid.sh

$(NAME) : ${OBJS}
	@${CC} ${FLAGS} $^ -o $@

.c.o:
	@${CC} ${FLAGS} -I./includes -c $< -o ${<:.c=.o}

clean:
	@rm -f ${OBJS}

fclean : clean
	@rm -f ${PROG} grid.txt

re : fclean all

.PHONY : all clean fclean re grid
