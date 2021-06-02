# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daoren <daoren@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 17:06:46 by daoren            #+#    #+#              #
#    Updated: 2021/06/02 18:54:19 by daoren           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###▼▼▼<src-updater-do-not-edit-or-remove>▼▼▼
# **************************************************************************** #
# **   Generated with https://github.com/lorenuars19/makefile-src-updater   ** #
# **************************************************************************** #

SRCS = \
	./srcs/utils/ft_printf_utils1.c \
	./srcs/utils/ft_printf_utils.c \
	./srcs/utils/ft_printf_utils3.c \
	./srcs/utils/ft_printf_utils4.c \
	./srcs/utils/ft_printf_utils2.c \
	./srcs/convert/convert_c.c \
	./srcs/convert/convert_u.c \
	./srcs/convert/convert_di.c \
	./srcs/convert/convert_percent.c \
	./srcs/convert/convert_x.c \
	./srcs/convert/convert_s.c \
	./srcs/convert/convert_upper_x.c \
	./srcs/convert/convert_p.c \

HEADERS = \
	./includes/ft_printf.h\

###▲▲▲<src-updater-do-not-edit-or-remove>▲▲▲

OBJS = $(SRCS:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

all : $(NAME)

allup : all clean

$(NAME) : $(OBJS)
	ar -rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re allup