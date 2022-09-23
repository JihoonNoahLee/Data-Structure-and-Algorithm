# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/21 19:08:42 by jihoolee          #+#    #+#              #
#    Updated: 2022/09/23 15:40:21 by jihoolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	list

CC		=	c++
CFLAGS 	=	-Iinclude/ -Wall -Wextra -Werror
RM		=	rm -rf

SRCS	=	main.cpp
OBJ_DIR	=	obj
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.cpp=.o))

all : $(NAME)

$(OBJ_DIR)/%.o : %.cpp
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
