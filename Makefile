NAME	:= push_swap
CFLAGS	:= -Wextra -Wall -Werror
SRCS	:= try.c algo.c instructions.c apply_a.c apply_b.c instructions_utils.c possibilitya.c possibilityb.c sort_util.c lst_utils.c ft_split.c parsing_utils.c errors.c parsing.c other.c parsing2.c instructions2.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
#	@${MAKE} -C ./libft fclean
	@rm -rf $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libmlx