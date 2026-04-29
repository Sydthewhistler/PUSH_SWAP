# push_swap — stack-sorting program
# Usage: make [all | clean | fclean | re]

NAME    := push_swap
LIBFT   := ./libft/libft.a

CC      := clang
CFLAGS  := -Wall -Wextra -Werror -g3

INC     := inc/
SRC_DIR := srcs/
OBJ_DIR := obj/

RM      := rm -rf

SRCS    := $(wildcard $(SRC_DIR)algorithm/*.c)       \
           $(wildcard $(SRC_DIR)commands/*.c)         \
           $(wildcard $(SRC_DIR)utils_functions/*.c)

OBJS    := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# ─── Targets ──────────────────────────────────────────────────────────────────

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INC) $^ -o $@
	@printf "\033[32m[OK]\033[0m %s built successfully\n" $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft --no-print-directory

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -I$(INC) -c $< -o $@

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) clean -C ./libft --no-print-directory
	@printf "\033[33m[clean]\033[0m object files removed\n"

fclean: clean
	@$(RM) $(NAME) $(LIBFT)
	@printf "\033[33m[fclean]\033[0m binaries removed\n"

re: fclean all
