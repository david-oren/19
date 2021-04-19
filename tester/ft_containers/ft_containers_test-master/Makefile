# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/24 20:21:03 by charles           #+#    #+#              #
#    Updated: 2020/04/26 09:34:27 by charles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_CONTAINERS_DIR = ../ft_containers
PYTHON = python3
PRETTIER = prettier.py
NAME = ft_containers_test
SEGV_WRAPPER = segv_wrapper.sh
SEGV_WRAPPER_OUT = segv_wrapper.out
SRC_DIR = src

CXX = clang++
CXXFLAGS = -std=c++98 -O0 -Wall -Wextra -I$(FT_CONTAINERS_DIR) -I.

SRC = $(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJ = $(SRC:.cpp=.o)
INC = ft_containers_test.hpp

run: all
	@./$(SEGV_WRAPPER) ./$(NAME) $(SEGV_WRAPPER_OUT) $(PRETTIER)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $@ $(OBJ)

$(SRC_DIR)/vector_test.o: $(SRC_DIR)/vector_test.cpp $(INC) $(FT_CONTAINERS_DIR)/Vector.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(SRC_DIR)/list_test.o: $(SRC_DIR)/list_test.cpp $(INC) $(FT_CONTAINERS_DIR)/List.hpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

%.o: %.cpp $(INC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
