NAME = libft.a

SRCS = ft_striteri.c ft_putendl_fd.c ft_strrchr.c ft_isdigit.c ft_isprint.c ft_strncmp.c ft_strnstr.c ft_toupper.c ft_atoi.c ft_calloc.c ft_substr.c ft_strlcat.c ft_strmapi.c ft_isalpha.c ft_strlcpy.c ft_putnbr_fd.c ft_split.c ft_memcpy.c ft_isascii.c ft_memset.c ft_itoa.c ft_putchar_fd.c ft_memmove.c ft_putstr_fd.c ft_strdup.c ft_bzero.c ft_tolower.c ft_strtrim.c ft_isalnum.c ft_memchr.c ft_memcmp.c ft_strlen.c ft_strjoin.c ft_strchr.c
OBJS = $(SRCS:.c=.o)

SRCS_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

SRCS_GNL = get_next_line.c
OBJS_GNL = $(SRCS_GNL:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $(OBJS_BONUS)

gnl: $(OBJS_GNL)
	$(AR) $(NAME) $(OBJS_GNL)

%.o: %.c
	$(CC) $(CFLAGS) -o $(@) -c $(<)

clean:
	rm -rf $(OBJS)
	rm -rf $(OBJS_BONUS)
	rm -rf $(OBJS_GNL)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus gnl clean fclean re
