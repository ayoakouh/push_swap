NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror

MANDATORY_DIR = mandatory
MANDATORY_SRCS = \
	$(MANDATORY_DIR)/ft_split.c \
	$(MANDATORY_DIR)/libft_utils1.c \
	$(MANDATORY_DIR)/libft_utils2.c \
	$(MANDATORY_DIR)/op_A.c \
	$(MANDATORY_DIR)/op_B.c \
	$(MANDATORY_DIR)/parssing.c \
	$(MANDATORY_DIR)/push_swap.c \
	$(MANDATORY_DIR)/sort_1.c \
	$(MANDATORY_DIR)/sort_2.c \
	$(MANDATORY_DIR)/sort_utils.c

MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

BONUS_DIR = bonus
GNL_DIR = Gnl
BONUS_SRCS = \
	$(BONUS_DIR)/checker_utils_1.c \
	$(BONUS_DIR)/checker_utils_2.c \
	$(BONUS_DIR)/checker.c \
	$(BONUS_DIR)/ft_split.c \
	$(BONUS_DIR)/op_a.c \
	$(BONUS_DIR)/op_b.c \
	$(BONUS_DIR)/checker_utils_3.c \
	$(BONUS_DIR)/parssing_of_checker.c \
	$(BONUS_DIR)/$(GNL_DIR)/get_next_line_utils.c \
	$(BONUS_DIR)/$(GNL_DIR)/get_next_line.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(MANDATORY_OBJS)
	$(CC) $(CFLAGS) $(MANDATORY_OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

clean:
	rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
