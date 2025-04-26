# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scavalli <scavalli@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/13 12:53:00 by scavalli          #+#    #+#              #
#    Updated: 2025/03/26 17:52:12 by scavalli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME = push_swap
# Directories
LIBFT = ./libft/libft.a
INC = inc/
SRC_DIR = srcs/
OBJ_DIR = obj/
# Compiler and CFlags
CC = clang
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

# Source Files
COMMANDS_FILE = $(wildcard $(SRC_DIR)commands/*.c)
UTILS_FUNCTIONS_FILE = $(wildcard $(SRC_DIR)utils_functions/*.c)
ALGORITHM_FILE = $(wildcard $(SRC_DIR)algorithm/*.c)

# Concatenate all source files
SRCS = $(COMMANDS_FILE) $(UTILS_FUNCTIONS_FILE) $(ALGORITHM_FILE)

# Generate corresponding object files
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

# Build rules
start:
	@echo "Fichiers sources : $(SRCS)"
	@echo "Fichiers objets : $(OBJ)"
	@make all

$(LIBFT):
	@make -C ./libft

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "Liaison de $@"
	$(CC) $(CFLAGS) -I$(INC) $(OBJ) $(LIBFT) -o $(NAME)

# Compilation des fichiers objets à partir des fichiers sources
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "Compilation de $<"
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@echo "Nettoyage des fichiers objets"
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft

fclean: clean
	@echo "Nettoyage de l'exécutable et de la bibliothèque"
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all

make restart : fclean start

# Les cibles factices représentent des actions, pas des fichiers
.PHONY: start all clean fclean re