NAME		= so_long

MLX_DIR		= ./minilibx-linux
LIBFT_DIR	= ./includes/libft
PRINTF_DIR	= ./includes/ft_printf
GNL_DIR		= ./includes/get_next_line

CC			= cc
CFLAGS		= -Wall -Wextra -Werror \
			  -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -I$(GNL_DIR)

MLX_LIB		= $(MLX_DIR)/libmlx.a
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lX11 -lXext

LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF		= $(PRINTF_DIR)/libftprintf.a

SRC			= so_long_main.c \
			  so_long_map.c \
			  so_long_map_control.c \
			  so_long_path_control.c \
			  so_long_move.c \
			  so_long_mlx.c \
			  $(GNL_DIR)/get_next_line.c \
			  $(GNL_DIR)/get_next_line_utils.c

OBJ			= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT_DIR)
	make -C $(PRINTF_DIR)
	make -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	make clean -C $(MLX_DIR)
	rm -f $(NAME)

re: fclean all
