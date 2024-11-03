/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_find_lowest_int.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:17:44 by eduribei          #+#    #+#             */
/*   Updated: 2024/11/01 18:53:39 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

// needs testing!!!
t_dll *ft_dclst_find_lowest_int(t_dll **tail, int offset)
{
	t_dll	*trav;
	t_dll	*lowest_node;
	int		value;
	int		lowest_val;
	size_t	safe_count;

	if (!tail || !(*tail))
		return (NULL);
	safe_count = 0;
	trav = *tail;
	lowest_node = trav;
	while(1)
	{	
		value = *(int *)((char *)trav + offset);
		lowest_val = *(int *)((char *)lowest_node + offset);
		if (value < lowest_val)
			lowest_node = trav;
		trav = trav->next;
		safe_count++;
		if (trav == *tail)
			break ;
		if (safe_count == MAXLISTLOOPS || trav == NULL)
			ft_error_exit("List not circular. Check list structure.\n", 1);
	}
	return (lowest_node);
}
