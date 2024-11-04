/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_sa_sb_ss.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:23:04 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../play_swap.h"

static bool	swap(t_dll **tail, int llen)
{
	t_dll	*temp;
		
	if (llen == 0 || llen == 1)
		return (false);
	else if (llen == 2)
	{
		(*tail) = (*tail)->next;
		return (true);
	}
	else
	{
		temp = (*tail)->next;
		(*tail)->next = (*tail)->next->next;
		(*tail)->next->prev = (*tail);
		temp->next = temp->next->next;
		temp->prev = (*tail)->next;
		temp->prev->next = temp;
		temp->next->prev = temp;
	}
	return (true);
}

void	sa(t_info *s, int fd)
{
	if (swap(&(s->a), s->a_len))
		dprintf(fd, "sa\n");
}

void	sb(t_info *s, int fd)
{
	if (swap(&(s->b), s->b_len))
		dprintf(fd, "sb\n");
}

void	ss(t_info *s, int fd)
{
	bool	sa;
	bool	sb;

	sa = false;
	sb = false;
	if (swap(&(s->a), s->a_len))
		sa = true;
	if (swap(&(s->b), s->b_len))
		sb = true;
	if (sa && sb)
		dprintf(fd, "ss\n");
	else if (sa && !sb)
		dprintf(fd, "sa\n");
	else if (!sa && sb)
		dprintf(fd, "sb\n");
}
