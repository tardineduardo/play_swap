/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:02:36 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/01 17:51:40 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdint.h>
# include <stddef.h>
# include <stdbool.h>
# include <stdarg.h>
# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <bits/posix1_lim.h>

typedef struct s_dlist
{
	int				arg;
	int				index;
	void			*content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}				t_dll;

// conversions
int		ft_atoi(const char *nptr);

// errors
void	ft_error_exit(char *message, int exit_number) __attribute__((noreturn));
void	ft_perror_exit(char *message, int exit_number) __attribute__((noreturn));

// memory
void	ft_bzero(void *s, size_t n);

// validations
int		ft_isdigit(int c);
int		ft_isspace(int c);

// strings
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

// printing
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_puthex_upp_int(unsigned int n, int fd);
int		ft_puthex_low_int_fd(unsigned int n, int fd);
int		ft_putuns_fd(unsigned int n, int fd);
int		ft_puthex_lo_long_fd(unsigned long long int n, int fd);

//lists - dclist
t_dll	*ft_dclstnew(void *content);
int		ft_dclstsize(t_dll **tail);
void	ft_dclstadd_back(t_dll **tail, t_dll *new);
void	ft_dclstadd_front(t_dll **tail, t_dll *new);
t_dll	*ft_dclsttrav_to_index(t_dll **tail, int index);
t_dll	*ft_dclst_find_value(t_dll **tail, int value, int offset);
t_dll	*ft_dclst_find_lowest_int(t_dll **tail, int offset);
t_dll	*ft_dclst_find_lowest_abs(t_dll **tail, int offset);
t_dll	*ft_dclst_find_highest_int(t_dll **tail, int offset);
bool	ft_dclst_clock_sortd(t_dll **tail, char mode, int offset);
bool	ft_dclst_circ_sortd(t_dll **tail, char type, char mode, int offset);
bool	ft_dclst_list_sortd(t_dll **tail, char *type, char mode, int offset);
int		ft_dclst_dist_head_bidi(t_dll **tail, t_dll *node);
int		ft_dclst_dist_head_bidi_len(t_dll **tail, t_dll *node, int list_len);
int		ft_dclst_dist_head_unid(t_dll **tail, t_dll *nd, char mode);
int		ft_dclst_dist_head_unid_len(t_dll **tail, t_dll *nd, int llen, char mode);
t_dll	*ft_dclst_find_node(t_dll **tail, t_dll *node);

// printf
int		ft_printf(const char *input, ...);
int		ft_dprintf(int fd, const char *input, ...);
int		ft_count_and_put_chr(va_list args, int fd);
int		ft_count_and_put_str(va_list args, int fd);
int		ft_count_and_put_int(va_list args, int fd);
int		ft_count_and_put_ptr(va_list args, int fd);
int		ft_count_and_put_uns(va_list args, int fd);
int		ft_count_and_put_hex_l(va_list args, int fd);
int		ft_count_and_put_hex_u(va_list args, int fd);

// sort
void	ft_sort_int_array_bubble(int *array, size_t len);

# ifndef MAXLISTLOOPS
#  define MAXLISTLOOPS 1000000000
# endif

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"


#endif
