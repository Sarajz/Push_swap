# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarajime <sarajime@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 11:41:39 by sarajime          #+#    #+#              #
#    Updated: 2024/03/13 18:00:17 by sarajime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker_bonus 
FLAGS = -Wall -Werror -Wextra
SRC_DIR = src
SRC_DIR_BONUS = src_bonus

FILES = ft_error.c ft_isalnum.c ft_split.c ft_strjoin.c init_nodes.c \
		node_push.c node_reverse_rotate.c node_rotate.c node_swap.c node_utils.c \
		parse.c push_swap.c sort_it.c stack_utils.c \

FILES_BONUS = ft_error_bonus.c ft_isalnum_bonus.c ft_split_bonus.c \
	ft_strjoin_bonus.c init_nodes_bonus.c node_push_bonus.c node_reverse_rotate_bonus.c \
	node_rotate_bonus.c node_swap_bonus.c node_utils_bonus.c parse_bonus.c \
	sort_it_bonus.c stack_utils_bonus.c utils_bonus.c checker_bonus.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c \


OBJECTS = $(addprefix $(SRC_DIR)/, $(FILES:.c=.o))
OBJECTS_BONUS = $(addprefix $(SRC_DIR_BONUS)/, $(FILES_BONUS:.c=.o))
INCS = -I push_swap.h
INCS_BONUS = -I push_swap_bonus.h

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(SRC_DIR_BONUS)/%.o: $(SRC_DIR_BONUS)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS_BONUS)
	

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME) 

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJECTS_BONUS)
	$(CC) $(CFLAGS) $(OBJECTS_BONUS) -o $(NAME_BONUS)
	
clean:
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	rm -rf $(OBJECTS) $(OBJECTS_BONUS)
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

norm:
	cd src && norminette

.PHONY: all fclean clean re bonus norm
