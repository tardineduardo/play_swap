/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dclst_is_circle_sorted.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:57:54 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static bool ft_check_int_one_increment_r(t_dll **tail, int offset)
{
    int     curr;
    int     next;
    t_dll   *trav;
    int     llen;
    int     i;

    llen = ft_dclstsize(tail);
    trav = ft_dclst_find_lowest_int(tail, offset);
    i = 0;
    while (i < llen)
    {
        curr = *(int *)((char *)trav + offset);
        next = *(int *)((char *)trav->next + offset);
        if (curr != (next + 1) % llen)
            return (false);
        trav = trav->next;
        i++;
    }
    return (true);
}

static bool ft_check_int_one_increment(t_dll **tail, int offset)
{
	int 	curr;
	int		next;
	t_dll *trav;
	int		llen;
	int		i;

	llen = ft_dclstsize(tail);
	trav = ft_dclst_find_lowest_int(tail, offset);
	i = 0;
	while(i < llen)
	{
		curr = *(int *)((char *)trav + offset);
		next = *(int *)((char *)trav->next + offset);
		if (curr != next - 1)
			if (curr != llen - 1 && next != 0)
				return (false);
		trav = trav->next;
		i++;
	}
	return (true);
}


static bool ft_check_int_normal(t_dll **tail, int offset)
{
	int 	curr;
	int		next;
	t_dll *trav;
	int		len;

	len = ft_dclstsize(tail);
	trav = ft_dclst_find_lowest_int(tail, offset);
	while(len > 1)
	{
		curr = *(int *)((char *)trav + offset);
		next = *(int *)((char *)trav->next + offset);
		if (curr > next)
			return (false);
		trav = trav->next;
		len--;
	}
	return (true);
}

static bool ft_check_int_reverse(t_dll **tail, int offset)
{
	int 	curr;
	int		next;
	t_dll *trav;
	int		len;

	len = ft_dclstsize(tail);
	trav = ft_dclst_find_highest_int(tail, offset);
	while(len > 1)
	{
		curr = *(int *)((char *)trav + offset);
		next = *(int *)((char *)trav->next + offset);
		if (curr < next)
			return (false);
		trav = trav->next;
		len--;
	}
	return (true);
}
/* type i-int | modes n-normal, r-reverse, i-plus1 o-plus1rev| offssetof(struct, variable)*/
bool ft_dclst_circ_sortd(t_dll **tail, char type, char mode, int offset)
{
	if (type == 'i')
		if (mode == 'n')
			return (ft_check_int_normal(tail, offset));
		else if (mode == 'r')
			return (ft_check_int_reverse(tail, offset));
		else if (mode == 'i')
			return (ft_check_int_one_increment(tail, offset));
		else if (mode == 'o')
			return (ft_check_int_one_increment_r(tail, offset));
		else
			ft_perror_exit("is_stack_sorted: invalid mode", 1); /// IMPROVE ERROR
	else
		ft_perror_exit("is_stack_sorted: invalid type", 1);  /// IMPROVE ERROR
	return (false);
}
