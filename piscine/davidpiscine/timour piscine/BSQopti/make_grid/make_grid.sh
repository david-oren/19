gcc -Wall -Wextra -Werror make_grid/make_grid.c make_grid/ft_putnbr.c -o grid.o
./grid.o > grid.txt
rm grid.o