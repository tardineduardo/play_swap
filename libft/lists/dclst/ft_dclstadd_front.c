/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:48:40 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// front means the start of the list, taking position zero.
void	ft_dclstadd_front(t_dll **tail, t_dll *new)
{
	
	if (*tail == NULL)
	{
		*tail = new;
		new->next = new;
	}
	else
	{
		new->next = (*tail)->next;
		(*tail)->next = new;
	}
}
