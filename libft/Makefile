CONV =	conv/ft_atoi.c \

ERROR =	error/ft_error_exit.c \
		error/ft_perror_exit.c \

LISTS =	lists/dclst/ft_dclistsize.c \
		lists/dclst/ft_dclstadd_back.c \
		lists/dclst/ft_dclstadd_front.c \
		lists/dclst/ft_dclstnew.c \
		lists/dclst/ft_dclsttrav_to_index.c \
	
MEM = 	mem/ft_bzero.c \

STRING =	string/ft_strlen.c \
			string/ft_strcmp.c \

VALID =	valid/ft_isdigit.c \
		valid/ft_isspace.c \

SORT =	sort/ft_sort_int_array_bubble.c

OBJS =	$(CONV:.c=.o) $(ERROR:.c=.o) \
		$(LISTS:.c=.o) $(VALID:.c=.o) $(MEM:.c=.o) \
		$(STRING:.c=.o)  \
		$(SORT:.c=.o) \

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@$(MAKE) clean

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re