# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 12:53:00 by scavalli          #+#    #+#              #
#    Updated: 2025/05/08 16:35:39 by scavalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = ./libft/libft.a
INC = inc/
SRC_DIR = srcs/
OBJ_DIR = obj/
CC = clang
CFLAGS = -Wall -Werror -Wextra -g3
RM = rm -f

COMMANDS_FILE = $(wildcard $(SRC_DIR)commands/*.c)
UTILS_FUNCTIONS_FILE = $(wildcard $(SRC_DIR)utils_functions/*.c)
ALGORITHM_FILE = $(wildcard $(SRC_DIR)algorithm/*.c)

SRCS = $(COMMANDS_FILE) $(UTILS_FUNCTIONS_FILE) $(ALGORITHM_FILE)

OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
	@make all

$(LIBFT):
	@make -C ./libft

all: $(NAME)
	@echo "\n\e[32mall files compiled\e[0m\n"

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INC) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all

make restart : fclean start

.PHONY: start all clean fclean re
