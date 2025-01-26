source = ft_split.c libft_utils2.c libft_utils1.c op_A.c op_B.c parssing.c push_swap.c\
			sorting.c

objects = $(source:.c=.o)

NAME = push_swap

CFLAGS = -Werror -Wall -Wextra

CC = cc

RM = rm -rf

all: $(NAME)

$(NAME): $(objects)
	$(CC) $(CFLAGS) $(objects) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(objects)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#-fsanitize=address -g

# CC = cc
# CFLAGS = -Wall -Wextra -Werror -fsanitize=address 

# SRCS            =    ft_split.c libft_utils2.c libft_utils1.c op_A.c op_B.c parssing.c push_swap.c \
# 					#  parse_one.c 
# OBJS            = $(SRCS:.c=.o)

# BONUS            = 
# BONUS_OBJS        = $(BONUS:.c=.o)

# RM                = rm -f

# NAME            = push_swap.a

# all:    $(NAME)

# bonus:    $(BONUS_OBJS)
# 	ar rc $(NAME) $^
# $(NAME):    $(OBJS)
# 	ar rc $(NAME) $^
# %.o: %.c libft.h
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	$(RM) $(OBJS) $(BONUS_OBJS)

# fclean:    clean
# 	$(RM) $(NAME)

# re: fclean $(NAME)
# # -fsanitize=address -g