NAME = push_swap
SRCS = ft_check.c ft_error.c ft_exec_min_cmds.c ft_find_idx.c ft_find_max.c ft_find_min.c ft_find_min_cmds.c ft_free_buff.c ft_free_nums.c ft_get_cmds.c ft_get_cmds_total.c ft_get_min_cmds.c ft_init_cmd.c ft_init_cmds.c ft_init_nums.c ft_init_stacks.c ft_list_add_back.c ft_list_add_front.c ft_list_del.c ft_list_is_sorted.c ft_list_new.c ft_nums_is_sorted.c ft_nums_to_list.c ft_parse.c ft_push.c ft_rotate.c ft_rotate_reverse.c ft_sort_five.c ft_sort_more.c ft_sort_three.c ft_swap.c push_swap.c
OBJS = $(SRCS:.c=.o)

NAME_BONUS = checker
SRCS_BONUS = checker.c ft_check.c ft_error.c ft_exec_min_cmds.c ft_find_idx.c ft_find_max.c ft_find_min.c ft_find_min_cmds.c ft_free_buff.c ft_free_nums.c ft_get_cmds.c ft_get_cmds_total.c ft_get_min_cmds.c ft_init_cmd.c ft_init_cmds.c ft_init_nums.c ft_init_stacks.c ft_list_add_back.c ft_list_add_front.c ft_list_del.c ft_list_is_sorted.c ft_list_new.c ft_nums_is_sorted.c ft_nums_to_list.c ft_parse.c ft_push.c ft_rotate.c ft_rotate_reverse.c ft_sort_five.c ft_sort_more.c ft_sort_three.c ft_swap.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -g -fsanitize=address -Wall -Werror -Wextra
LDLIBS = -Llibft -lft

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LDLIBS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) $(LDLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	make -C libft clean
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)

fclean: clean
	make -C libft fclean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
