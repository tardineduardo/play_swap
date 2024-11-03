/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclsttrav_to_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:52:04 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_dll	*ft_dclsttrav_to_index(t_dll **tail, int index)
{
	int		i;
	int		len;
	t_dll *trav;

	trav = *tail;
	len = ft_dclstsize(tail);
	if (index > len - 1 || len == 0)
		return (NULL);
	i = index;
	while (i >= 0)
	{
		trav = trav->next;
		i--;
	}
	return (trav);
}
