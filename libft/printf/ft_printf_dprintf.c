/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:46:47 by eduribei          #+#    #+#             */
/*   Updated: 2024/06/02 13:47:52 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_none(char c, int fd);
static int	ft_handle_last(char last, int count, int fd);
static int	ft_check_type(char c, va_list args, int fd);

int	ft_printf(const char *input, ...)
{
	int		count;
	int		len;
	int		fd;
	int		a;
	va_list	args;

	fd = STDOUT_FILENO;
	if (!input)
		return (-1);
	va_start(args, input);
	len = ft_strlen(input);
	count = 0;
	a = 0;
	while (a < len - 1)
	{
		if (input[a] == '%')
			count += ft_check_type(input[++a], args, fd);
		else
			count += ft_putchar_fd(input[a], fd);
		a++;
	}
	va_end(args);
	return (ft_handle_last(input[a], count, fd));
}

int	ft_dprintf(int fd, const char *input, ...)
{
	int		count;
	int		len;
	int		a;
	va_list	args;

	if (!input)
		return (-1);
	va_start(args, input);
	len = ft_strlen(input);
	count = 0;
	a = 0;
	while (a < len - 1)
	{
		if (input[a] == '%')
			count += ft_check_type(input[++a], args, fd);
		else
			count += ft_putchar_fd(input[a], fd);
		a++;
	}
	va_end(args);
	return (ft_handle_last(input[a], count, fd));
}

static int	ft_none(char c, int fd)
{
	write(fd, "%", 1);
	write(fd, &c, 1);
	return (2);
}

static int	ft_handle_last(char last, int count, int fd)
{
	if (last == '%')
	{
		count = -1;
		return (count);
	}
	else if (last == '\0')
	{
		return (count);
	}
	else
	{
		ft_putchar_fd(last, fd);
		return (++count);
	}
}

static int	ft_check_type(char c, va_list args, int fd)
{
	if (c == '%')
	{
		write(fd, "%", 1);
		return (1);
	}
	else if (c == 'c')
		return (ft_count_and_put_chr(args, fd));
	else if (c == 's')
		return (ft_count_and_put_str(args, fd));
	else if (c == 'p')
		return (ft_count_and_put_ptr(args, fd));
	else if (c == 'd' || c == 'i')
		return (ft_count_and_put_int(args, fd));
	else if (c == 'u')
		return (ft_count_and_put_uns(args, fd));
	else if (c == 'x')
		return (ft_count_and_put_hex_l(args, fd));
	else if (c == 'X')
		return (ft_count_and_put_hex_u(args, fd));
	else
		return (ft_none(c, fd));
}
