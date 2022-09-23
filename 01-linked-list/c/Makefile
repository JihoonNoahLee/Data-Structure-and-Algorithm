# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 15:36:49 by jihoolee          #+#    #+#              #
#    Updated: 2022/09/23 15:57:15 by jihoolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	linked_list

CC		=	clang
CFLAGS 	=	-Iinclude/ -Wall -Wextra -Werror
RM		=	rm -rf

SRC		=	main.c
SRC_DIR	=	src/
SRCS	=	$(addprefix $(SRC_DIR), $(SRC))

OBJ_DIR	=	obj/
OBJS	=	$(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all : $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
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