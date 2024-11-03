/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_pa_pb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:07:25 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../play_swap.h"

static void ft_push_multi_to_empty(t_dll **src, t_dll **dest)
{
	(*dest) = (*src)->next;
	(*src)->next = (*src)->next->next;
	(*src)->next->prev = *src;
	(*dest)->next = *dest;
	(*dest)->prev = *dest;
}

static void ft_push_single_to_multi(t_dll **src, t_dll **dest)
{
	(*src)->next = (*dest)->next;
	(*src)->prev = (*dest);
	(*dest)->next = *src;
	(*dest)->next->next->prev = (*dest)->next;
	*src = NULL;
}

static void ft_push_multi_to_multi(t_dll **src, t_dll **dest)
{
	t_dll	*temp;

	temp = (*src)->next;
	(*src)->next->next->prev = (*src);
	(*src)->next = (*src)->next->next;
	temp->next = (*dest)->next;
	temp->prev = (*dest);
	(*dest)->next = temp;
	temp->next->prev = temp;
}

void pa(t_info *s, int fd)
{
	if (s->b_len == 0)
		return;
	else if (s->b_len == 1 && s->a_len == 0)
	{
		s->a = s->b;
		s->b = NULL;
		ft_dprintf(fd, "pa\n");
		s->b_len--;
		s->a_len++;
		return;
	}
	else if (s->b_len > 1 && s->a_len == 0)
		ft_push_multi_to_empty(&(s->b), &(s->a));
	else if (s->b_len == 1 && s->a_len >= 1)
		ft_push_single_to_multi(&(s->b), &(s->a));
	else if (s->b_len >= 1 && s->a_len >= 1)
		ft_push_multi_to_multi(&(s->b), &(s->a));
	ft_dprintf(fd, "pa\n");
	s->b_len--;
	s->a_len++;
}

void pb(t_info *s, int fd)
{
	if (s->a_len == 0)
		return;
	else if (s->a_len == 1 && s->b_len == 0)
	{
		s->b = s->a;
		s->a = NULL;
		ft_dprintf(fd, "pb\n");
		s->a_len--;
		s->b_len++;
		return;
	}
	else if (s->a_len > 1 && s->b_len == 0)
		ft_push_multi_to_empty(&(s->a), &(s->b));
	else if (s->a_len == 1 && s->b_len >= 1)
		ft_push_single_to_multi(&(s->a), &(s->b));
	else if (s->a_len >= 1 && s->b_len >= 1)
		ft_push_multi_to_multi(&(s->a), &(s->b));
	ft_dprintf(fd, "pb\n");
	s->a_len--;
	s->b_len++;
}
