NAME = minitalk

LIBFT_NAME = libft.a
LIBFT_DIR = ./libft

CLIENT_NAME = client
CLIENT_SRCS = client.c
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

CLIENT_NAME_BONUS = client_bonus
CLIENT_SRCS_BONUS = client_bonus.c
CLIENT_OBJS_BONUS = $(CLIENT_SRCS_BONUS:.c=.o)

SERVER_NAME = server
SERVER_SRCS = server.c
SERVER_OBJS = $(SERVER_SRCS:.c=.o)

SERVER_NAME_BONUS = server_bonus
SERVER_SRCS_BONUS = server_bonus.c
SERVER_OBJS_BONUS = $(SERVER_SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra -g
LDLIBS = -L$(LIBFT_DIR) -lft

all: $(NAME)

$(NAME): $(CLIENT_NAME) $(SERVER_NAME)

bonus: $(CLIENT_NAME_BONUS) $(SERVER_NAME_BONUS)

$(CLIENT_NAME): $(CLIENT_OBJS)
	make -C $(LIBFT_DIR) $(LIBFT_NAME)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(CLIENT_OBJS) $(LDLIBS)

$(CLIENT_NAME_BONUS): $(CLIENT_OBJS_BONUS)
	make -C $(LIBFT_DIR) $(LIBFT_NAME)
	$(CC) $(CFLAGS) -o $(CLIENT_NAME_BONUS) $(CLIENT_OBJS_BONUS) $(LDLIBS)

$(SERVER_NAME): $(SERVER_OBJS)
	make -C $(LIBFT_DIR) $(LIBFT_NAME)
	$(CC) $(CLAGS) -o $(SERVER_NAME) $(SERVER_OBJS) $(LDLIBS)

$(SERVER_NAME_BONUS): $(SERVER_OBJS_BONUS)
	make -C $(LIBFT_DIR) $(LIBFT_NAME)
	$(CC) $(CLAGS) -o $(SERVER_NAME_BONUS) $(SERVER_OBJS_BONUS) $(LDLIBS)

clean:
	rm -rf $(CLIENT_OBJS)
	rm -rf $(CLIENT_OBJS_BONUS)
	rm -rf $(SERVER_OBJS)
	rm -rf $(SERVER_OBJS_BONUS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(CLIENT_NAME)
	rm -rf $(CLIENT_NAME_BONUS)
	rm -rf $(SERVER_NAME)
	rm -rf $(SERVER_NAME_BONUS)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all $(NAME) bonus clean fclean re
