/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 14:03:22 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/18 15:35:40 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			a;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		*ptr = 0x00;
		ptr++;
		a++;
	}
}
