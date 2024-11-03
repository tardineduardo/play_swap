PRINTF =	printf/ft_printf_dprintf.c \
			printf/ft_printf_int_chr_str.c \
			printf/ft_printf_hex_ptr_uns.c \

PUTS =	puts/ft_putchar_fd.c \
		puts/ft_puthex_int_low_fd.c \
		puts/ft_puthex_int_upp_fd.c \
		puts/ft_puthex_long_low_fd.c \
		puts/ft_putnbr_fd.c \
		puts/ft_putstr_fd.c \
		puts/ft_putuns_fd.c \

CONV =	conv/ft_atoi.c \


ERROR =	error/ft_error_exit.c \
		error/ft_perror_exit.c \

LISTS =	lists/dclst/ft_dclistsize.c \
		lists/dclst/ft_dclstadd_back.c \
		lists/dclst/ft_dclstadd_front.c \
		lists/dclst/ft_dclstnew.c \
		lists/dclst/ft_dclsttrav_to_index.c \
		lists/dclst/ft_dclst_find_value.c \
		lists/dclst/ft_dclst_find_lowest_int.c \
		lists/dclst/ft_dclst_find_lowest_abs.c \
		lists/dclst/ft_dclst_find_highest_int.c \
		lists/dclst/ft_dclst_is_circle_sorted.c \
		lists/dclst/ft_dclst_is_list_sorted.c \
		lists/dclst/ft_dclst_dist_head_bidi_len.c \
		lists/dclst/ft_dclst_dist_head_bidi.c \
		lists/dclst/ft_dclst_dist_head_unid_len.c \
		lists/dclst/ft_dclst_dist_head_unid.c \
		lists/dclst/ft_dclst_clock_sortd.c \
		lists/dclst/ft_dclst_find_node.c \
	
MEM = 	mem/ft_bzero.c \

STRING =	string/ft_strlen.c \
			string/ft_strcmp.c \

VALID =	valid/ft_isdigit.c \
		valid/ft_isspace.c \

SORT =	sort/ft_sort_int_array_bubble.c


OBJS =	$(PRINTF:.c=.o) $(CONV:.c=.o) $(ERROR:.c=.o) \
		$(LISTS:.c=.o) $(VALID:.c=.o) $(MEM:.c=.o) \
		$(PUTS:.c=.o) $(STRING:.c=.o)  \
		$(SORT:.c=.o) \

#$(GNL:.c=.o)
#$(DEBUG:.c=.o)
#$(FDS:.c=.o)


CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

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