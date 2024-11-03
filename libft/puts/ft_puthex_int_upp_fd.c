/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_int_upp_fd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:08:40 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 13:08:41 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puthex_upp_int(unsigned int n, int fd)
{
	int		count;
	char	hex_str[9];
	int		a;

	count = 0;
	a = 0;
	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return (1);
	}
	while (n > 0)
	{
		hex_str[a++] = "0123456789ABCDEF"[n % 16];
		n /= 16;
	}
	while (--a >= 0)
	{
		ft_putchar_fd(hex_str[a], fd);
		count++;
	}
	return (count);
}