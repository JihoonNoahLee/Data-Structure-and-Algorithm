# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 00:04:31 by jihoolee          #+#    #+#              #
#    Updated: 2022/10/07 01:15:11 by jihoolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	queue

CC		=	c++
CFLAGS 	=	-Iinclude/ -Wall -Wextra -Werror -std=c++11
RM		=	rm -rf

SRC		=	main.cpp
SRC_DIR	=	src/
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
