# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihoolee <jihoolee@student.42SEOUL.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/23 15:36:49 by jihoolee          #+#    #+#              #
#    Updated: 2022/09/28 19:53:30 by jihoolee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	linked_list

CC		=	clang
CFLAGS 	=	-Iinclude/ -Wall -Wextra -Werror
RM		=	rm -rf

SRC		=	main.c\
			add_at.c\
			add_back.c\
			add_front.c\
			clear_list.c\
			create_node.c\
			del_at.c\
			del_back.c\
			del_front.c\
			delone_node.c\
			find_idx.c\
			find_node.c\
			get_data_at.c\
			get_node_at.c\
			main.c\
			print_list.c

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
