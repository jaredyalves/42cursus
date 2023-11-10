NAME = so_long

SRCS = ft_error.c ft_read_map.c ft_draw_map.c ft_move_player.c ft_exit.c ft_game_play.c ft_check_map.c ft_check_ext.c ft_game_init.c ft_free_map.c ft_path_is_valid.c so_long.c
OBJS = $(SRCS:.c=.o)

MLX_DIR = ./lib/minilibx
LIBFT_DIR = ./lib/libft
FTPRINTF_DIR = ./lib/ft_printf

CC = cc
INCLUDE = -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(FTPRINTF_DIR)
CFLAGS = -Wall -Werror -Wextra -g $(INCLUDE)
LDLIBS = -L$(LIBFT_DIR) -lft -L$(FTPRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(MLX_DIR) all
	make -C $(LIBFT_DIR) all bonus gnl
	make -C $(FTPRINTF_DIR) all
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $(@) -c $(<)

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(FTPRINTF_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(FTPRINTF_DIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
