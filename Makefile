NAME	:= push_swap
CFLAGS	:= -Wextra -Wall -fsanitize=address -g
SRCS	:= try.c
LIBFT	:= ./libft/libft.a

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx