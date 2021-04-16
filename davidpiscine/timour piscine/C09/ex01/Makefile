SRC = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS = $(addprefix srcs/, ${SRC})
OBJS = ${SRCS:.c=.o}
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIB = libft.a

all : ${LIB}

${LIB} : ${OBJS}
	ar -rcs ${LIB} ${OBJS}

${OBJS} :
	${CC} ${FLAGS} -c -I./includes ${@:.o=.c} -o $@

clean:
	rm -f ${OBJS}

fclean : clean
	rm -f ${LIB}

re : fclean all

.PHONY : all clean fclean re