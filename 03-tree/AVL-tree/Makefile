# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 16:22:16 by jihoolee          #+#    #+#              #
#    Updated: 2022/10/28 16:27:11 by jihoolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	avl_tree

CC		=	c++
CFLAGS 	=	-Iinclude/ -Wall -Wextra -Werror -std=c++11
RM		=	rm -rf

SRC_DIR	=	src/
SRC		=	main.cpp\
			AVLTree.cpp
SRCS	=	$(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR	=	obj
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRC:.cpp=.o))

all : $(NAME)

$(OBJ_DIR)/%.o : $(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $^

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re