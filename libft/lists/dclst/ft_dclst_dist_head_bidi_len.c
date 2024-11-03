/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_dist_from_head_muld_len.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:21:30 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_dclst_dist_head_bidi_len(t_dll **tail, t_dll *node, int list_len)
{
	int		i;
	t_dll	*trav_fwd;
	t_dll	*trav_bck;

	if (!tail || !(*tail))
		return (0);
	i = 0;
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
	ft_perror_exit("Invalid parameters: can't find the head of the list.\n", 1);
}
