/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:41:34 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/28 15:43:49 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play_swap.h"

static void	put_a(t_dll **a, bool *index)
{
	int i = (*a)->arg;
	int m = (*a)->index;
	if (*index)
	{
		ft_printf(RED "\t\t\t+-----------+\n" RESET);
		ft_printf(RED "\t\t\t|\t" RESET "%i" BLUE "\t%i" RED "\t|\n" RESET, i, m);
		ft_printf(RED "\t\t\t+-----------+\n" RESET);
	}
	else
	{
		ft_printf(RED "\t\t\t+-------+\n" RESET);
		ft_printf(RED "\t\t\t|\t" RESET "%i" RED "\t|\n" RESET, i, m);
		ft_printf(RED "\t\t\t+-------+\n" RESET);
	}
}

static void	put_b(t_dll **b, bool *index)
{
	int i = (*b)->arg;
	int n = (*b)->index;
	if (*index)
	{
		ft_printf(YELLOW "\t\t\t\t\t\t\t+-----------+\n" RESET);
		ft_printf(YELLOW "\t\t\t\t\t\t\t|\t" RESET "%i" BLUE "\t%i" YELLOW "\t|\n" RESET, i, n);
		ft_printf(YELLOW "\t\t\t\t\t\t\t+-----------+\n" RESET);
	}
	else
	{
		ft_printf(YELLOW "\t\t\t\t\t\t+-------+\n" RESET);
		ft_printf(YELLOW "\t\t\t\t\t\t|\t" RESET "%i" YELLOW "\t|\n" RESET, i, n);
		ft_printf(YELLOW "\t\t\t\t\t\t+-------+\n" RESET);
	}
}

static void	put_ab(t_dll **a, t_dll **b, bool *index)
{
	int i = (*a)->arg;
	int m = (*a)->index;
	int j = (*b)->arg;
	int n = (*b)->index;
	if (*index)
	{
		ft_printf(RED "\t\t\t+-----------+" YELLOW "\t+-----------+\n" RESET);
		ft_printf(RED "\t\t\t|\t" RESET "%i" BLUE "\t%i" RED "\t|" YELLOW "\t|\t" RESET "%i" BLUE "\t%i" YELLOW "\t|\n", i, m, j, n);
		ft_printf(RED "\t\t\t+-----------+" YELLOW "\t+-----------+\n" RESET);
	}
	else
	{
		ft_printf(RED "\t\t\t+-------+" YELLOW "\t+-------+\n" RESET);
		ft_printf(RED "\t\t\t|\t" RESET "%i " RED "\t|" YELLOW "\t|\t" RESET "%i" YELLOW "\t|\n", i, m, j, n);
		ft_printf(RED "\t\t\t+-------+" YELLOW "\t+-------+\n" RESET);	
	}
}

void	ft_play_print(t_dll **a, t_dll **b, bool *index)
{
	t_dll *trav_a;
	t_dll *trav_b;
	t_dll *space_a;
	t_dll *space_b;
	int	index_a;
	int	index_b;
	int height;

	index_a = 0;
	index_b = 0;

	height = ft_dclstsize(a) + ft_dclstsize(b);

	ft_printf("\n");
	while (height > 0)
	{
		space_a = ft_dclsttrav_to_index(a, height - 1);
		space_b = ft_dclsttrav_to_index(b, height - 1);

		if (space_a)
		{
			trav_a = ft_dclsttrav_to_index(a, index_a);
			index_a++;
		}
		if (space_b)
		{
			trav_b = ft_dclsttrav_to_index(b, index_b);
			index_b++;
		}
		if (!space_a && !space_b)
			ft_printf("\n\n\n");
		else if (space_a && space_b)
			put_ab(&trav_a, &trav_b, index);			
		else if (space_a && !space_b)
			put_a(&trav_a, index);
		else if (!space_a && space_b)
			put_b(&trav_b, index);
	height--;
	}
	ft_printf("____________________________________________________\n");
	if (*index)
		ft_printf("\t\t\t   stack a\t\t   stack b\n");
	else
		ft_printf("\t\t\t stack a\t stack b\n");
	ft_printf("\n");
	return ;
}
