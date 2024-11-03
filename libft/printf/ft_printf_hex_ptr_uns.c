/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex_ptr_uns.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 13:11:21 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/23 13:11:22 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_count_and_put_hex_l(va_list args, int fd)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (ft_putstr_fd("0", 1));
	else
		return (ft_puthex_low_int_fd(n, fd));
}

int	ft_count_and_put_hex_u(va_list args, int fd)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (ft_putstr_fd("0", fd));
	else
		return (ft_puthex_upp_int(n, fd));
}

int	ft_count_and_put_ptr(va_list args, int fd)
{
	unsigned long long int	n;
	int						count;

	n = va_arg(args, unsigned long long int);

	count = 0;
	if (n == 0)
		return (ft_putstr_fd("(nil)", fd));
	else
	{
		count += ft_putstr_fd("0x", fd);
		count += ft_puthex_lo_long_fd(n, fd);
		return (count);
	}
}
int	ft_count_and_put_uns(va_list args, int fd)
{
	unsigned long long	n;
	
	n = va_arg(args, unsigned long long);
	return (ft_putuns_fd(n, fd));
}
