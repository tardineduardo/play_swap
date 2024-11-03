/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_find_value.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:42:18 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/28 20:30:29 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// needs testing!!!
t_dll	*ft_dclst_find_value(t_dll **tail, int value, int offset)
{
	t_dll	*trav;

	if (!tail || !(*tail))
		return (NULL);
	trav = (*tail)->next;
	while (1)
	{
		if (*(int *)((char *)trav + offset) == value)
			return (trav);
		trav = trav->next;
		if (trav == (*tail)->next)
			break ;
	}
	return (NULL);
}

// static t_dll	*ft_search_reverse(t_dll **tail, int value, int offset)
// {
// 	t_dll		*trav;

// 	trav = (*tail);
// 	if (*(int *)((char *)(trav + offset)) == value)
// 		return (trav);
// 	trav = trav->prev;
// 	while (trav != (*tail))
// 	{
// 		if (*(int *)((char *)(trav + offset)) == value)
// 			return (trav);
// 		trav = trav->prev;
// 	}
// 	return (NULL);
// }