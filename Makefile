NAME	:= push_swap
CFLAGS	:= -Wextra -Wall -fsanitize=address -g
SRCS	:= try.c algo.c instructions.c possibility.c
LIBFT	:= ./libft/libft.a

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@${MAKE} -C ./libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

clean:
#	@${MAKE} -C ./libft fclean
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx