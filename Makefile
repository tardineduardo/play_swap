OBJS = 	src/ft_init_stack.o \
		src/ft_validate_args.o \
		src/play_print.o \
		src/play.o \
		src/push_swap.h \

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

NAME = play_swap
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a
MOVES_PATH = ./moves
MOVES = $(MOVES_PATH)/moves.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MOVES)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MOVES)

clean:
		$(RM) $(NAME)

.PHONY: all clean
