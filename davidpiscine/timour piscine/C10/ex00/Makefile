SRCS = main.c ft_putstr.c ft_puterr.c ft_open_file.c
OBJS = ${SRCS:.c=.o}
CC = gcc
FLAGS = -Wall -Wextra -Werror
PROG = ft_display_file

all : ${PROG}

${PROG} : ${OBJS}
	${CC} ${FLAGS} $^ -o $@

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f ${OBJS}

fclean : clean
	rm -f ${PROG}

re : fclean all

.PHONY : all clean fclean re