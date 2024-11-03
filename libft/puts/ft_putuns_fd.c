/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 15:17:48 by eduribei          #+#    #+#             */
/*   Updated: 2024/05/22 10:28:02 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_get_digits(char *number, unsigned int n)
{
	int	a;

	a = 0;
	while (n >= 1)
	{
		number[a] = (n % 10) + 48;
		n = n / 10;
		a++;
	}
}

static int	ft_putzero(int fd)
{
	write(fd, "0", 1);
	return (1);
}

int	ft_putuns_fd(unsigned int n, int fd)
{
	int		count;
	int		print_len;
	char	number[12];

	count = 0;
	ft_bzero(number, 12);
	if (n == 0)
		return (ft_putzero(fd));
	ft_get_digits(number, n);
	print_len = ft_strlen(number) - 1;
	while (print_len >= 0)
	{
		write(fd, &number[print_len], 1);
		count++;
		print_len--;
	}
	return (count);
}
