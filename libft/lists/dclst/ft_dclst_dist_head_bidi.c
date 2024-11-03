/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_dist_head_bidi.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:21:30 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/30 18:50:34 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_dclst_dist_head_bidi(t_dll **tail, t_dll *node)
{
	int		i;
	int		list_len;
	t_dll	*trav_fwd;
	t_dll	*trav_bck;

	if (!tail || !(*tail))
		return (0);
	i = 0;
	list_len = ft_dclstsize(tail);
	if (list_len == -1)
		ft_error_exit("List size error.\n", 1);
	if (list_len == 0)
		return (0);
	if (list_len == 1)
		return (1);	
	trav_fwd = node;
	trav_bck = node;
	while (i < list_len)
	{
		if (trav_fwd == (*tail)->next)
			return (i);
		if (trav_bck == (*tail)->next)
			return (-i);
		i++;
		trav_fwd = trav_fwd->next;
		trav_bck = trav_bck->prev;	
	}
	ft_error_exit("ft_dclst_dist_from_head. Invalid parameters: can't find head of the list.\n", 1);
}
