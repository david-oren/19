SRCS = main.c ft_putstr.c ft_strlen.c write_number.c check_num.c ft_strcmp.c print_result.c print_result2.c other_functions.c other_functions2.c other_functions3.c free_all.c check_result.c check_result2.c
OBJS = ${SRCS:.c=.o}
CC = gcc
FLAGS = -Wall -Wextra -Werror
PROG = rush-02

all : ${PROG}

allup : all clean

${PROG} : ${OBJS}
	@${CC} ${FLAGS} $^ -o $@

.c.o:
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
	@rm -f ${OBJS}

fclean : clean
	@rm -f ${PROG}

re : fclean all

.PHONY : all clean fclean re allup