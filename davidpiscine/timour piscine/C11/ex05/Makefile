SRCS = ft_atoi.c ft_ope.c ft_putnbr.c ft_putstr.c ft_solve_eq.c main.c
OBJS = ${SRCS:.c=.o}
CC = gcc
FLAGS = -Wall -Wextra -Werror
PROG = do-op

all : ${PROG}

${PROG} : ${OBJS}
	@${CC} ${FLAGS} $^ -o $@

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
	@rm -f ${OBJS}

fclean : clean
	@rm -f ${PROG}

re : fclean all

.PHONY : all clean fclean re