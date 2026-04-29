# push_swap — stack-sorting program
# Usage: make [all | clean | fclean | re | visual]

NAME            := push_swap
CHECKER         := checker
LIBFT           := ./libft/libft.a
VISUALIZER_DIR  := push_swap_visualizer

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

# Checker shares everything except push_swap's main, adds its own
CHECKER_SRCS := $(filter-out $(SRC_DIR)algorithm/main.c, $(SRCS)) \
                $(SRC_DIR)checker/main.c
CHECKER_OBJS := $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(CHECKER_SRCS))

# ─── Targets ──────────────────────────────────────────────────────────────────

.PHONY: all clean fclean re visual

all: $(NAME) $(CHECKER)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INC) $^ -o $@
	@printf "\033[32m[OK]\033[0m %s built successfully\n" $(NAME)

$(CHECKER): $(CHECKER_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -I$(INC) $^ -o $@
	@printf "\033[32m[OK]\033[0m %s built successfully\n" $(CHECKER)

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
	@$(RM) $(NAME) $(CHECKER) $(LIBFT)
	@$(RM) $(VISUALIZER_DIR)/build
	@printf "\033[33m[fclean]\033[0m binaries removed\n"

re: fclean all

visual: all
	@./visualizer
