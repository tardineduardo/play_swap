/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_array_bubble.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 14:39:57 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/26 16:00:20 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void ft_sort_int_array_bubble(int *array, size_t len)
{
	size_t	i;
	size_t	swap_count;
	int		temp;

	swap_count = 1;
	while (swap_count)
	{
		i = 0;
		swap_count = 0;
		while (i < len - 1)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				swap_count++;
			}
			i++;
		}
	}	
}

