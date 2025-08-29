CC = cc

# Directories
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux

# Archives
LIBFT_A = $(LIBFT_DIR)/libft.a
MLX_A = $(MLX_DIR)/libmlx.a

# Include paths (adjust if your headers are elsewhere)
INCLUDE_LIBFT = -I$(LIBFT_DIR)
INCLUDE_MINILIBX = -I$(MLX_DIR)
# If you have project headers, add: -Iinclude
CFLAGS = -Wall -Wextra -g3 $(INCLUDE_LIBFT) $(INCLUDE_MINILIBX)

# Linker flags
MLX_LIBS = -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

NAME = cub3d

SRC =	src/quit_clean.c \
		src/parsing_lulu.c \
		src/file_check.c \
		src/real_distance.c \
		src/ray_direction.c \
		src/dda_algo.c \
		src/dda_algo_utils.c \
		src/draw_stripes.c \
		src/draw_stripes_utils.c \
		src/utils.c \
		src/init.c \
		src/main_alex.c

GREEN = \033[32m
RED = \033[31m
YELLOW = \033[33m
RESET = \033[0m

# Objects in build/
build/%.o: src/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

OBJ = $(SRC:.c=.o)
OBJ := $(OBJ:src/%=build/%)

# Build rules
$(NAME): $(LIBFT_A) $(MLX_A) $(OBJ)
	@$(CC) $(OBJ) $(MLX_LIBS) $(LIBFT_A) -o $@
	@echo "$(GREEN)Compilation successful ! ✅ $(RESET)"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR) --no-print-directory

$(MLX_A):
	@$(MAKE) -C $(MLX_DIR) --no-print-directory > /dev/null 2>/dev/null
	@echo "$(GREEN)libmlx.a created successfully ! ✅ $(RESET)"


all: $(NAME)

clean:
	@rm -rf build/
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory > /dev/null
	@echo "$(YELLOW)mlx object files cleaned. 🧹$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) clean --no-print-directory
	@echo "$(YELLOW)All object files cleaned. 🧹$(RESET)"

fclean:
	@rm -rf build/
	@$(MAKE) -C $(MLX_DIR) clean --no-print-directory > /dev/null
	@echo "$(YELLOW)mlx object files cleaned. 🧹$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR) fclean --no-print-directory
	@rm -f $(NAME)
	@echo "$(YELLOW)Executable cleaned. 🧹$(RESET)"

re: fclean all

valg: re
	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

.PHONY: all clean fclean re valg
