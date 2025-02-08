CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = M/ft_split.c M/libft_utils1.c M/libft_utils2.c M/op_A.c M/op_B.c \
		M/parssing.c M/push_swap.c M/sort_1.c M/sort_2.c M/sort_utils.c \
		M/sort_0.c \

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = bonus/checker_utils_1_bonus.c bonus/checker_utils_2_bonus.c bonus/checker_utils_3_bonus.c \
			bonus/checker_bonus.c bonus/ft_split_bonus.c bonus/op_a_bonus.c bonus/op_AB_bonus.c bonus/op_b_bonus.c \
			bonus/parssing_of_checker_bonus.c bonus/get_next_line_utils_bonus.c bonus/get_next_line_bonus.c\


BONUS_OBJS = $(BONUS_SRCS:.c=.o)

NAME = push_swap
BONUS_NAME = checker

all: $(NAME)

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJS): M/push_swap.h

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

$(BONUS_OBJS): bonus/checker_bonus.h bonus/get_next_line_bonus.h

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
