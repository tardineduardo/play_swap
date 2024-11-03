/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_dist_head_unid_len.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:21:30 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/30 18:50:19 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_dclst_dist_head_unid_len(t_dll **tail, t_dll *nd, int llen, char mode)
{
	int		i;
	t_dll	*trav;

	if (!tail || !(*tail))
		return (0);
	i = 0;
	trav = nd;
	while (i < llen)
	{
		if (mode == 'f')
		{
			if (trav == (*tail)->next)
				return (i);
			trav = trav->next;
		}
		else if (mode == 'r')
		{
			if (trav == (*tail)->next)
				return (i);
			trav = trav->prev;
		}
		i++;
	}
	ft_perror_exit("Invalid parameters: can't find the head of the list.\n", 1);
}
