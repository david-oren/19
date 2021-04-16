SRCS = main.c ft_putstr.c ft_open_file.c ft_rewrite_userinput.c ft_strcmp.c ft_puterr.c ft_putstr_err.c ft_strlen.c
OBJS = ${SRCS:.c=.o}
CC = gcc
FLAGS = -Wall -Wextra -Werror
PROG = ft_cat

all : ${PROG}

allup : all clean

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