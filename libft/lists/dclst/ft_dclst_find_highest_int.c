/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_find_highest_int.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:17:44 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/01 18:53:06 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// needs testing!!!
t_dll *ft_dclst_find_highest_int(t_dll **tail, int offset)
{
	t_dll	*trav;
	t_dll	*highest_node;
	int		value;
	int		highest_val;
	size_t	safe_count;

	if (!tail || !(*tail))
		return (NULL);
	safe_count = 0;
	trav = *tail;
	highest_node = trav;
	while(1)
	{	
		value = *(int *)((char *)trav + offset);
		highest_val = *(int *)((char *)highest_node + offset);
		if (value > highest_val)
			highest_node = trav;
		trav = trav->next;
		safe_count++;
		if (trav == *tail)
			break ;
		if (safe_count == MAXLISTLOOPS || trav == NULL)
			ft_error_exit("List not circular. Check list structure.\n", 1);
	}
	return (highest_node);
}
