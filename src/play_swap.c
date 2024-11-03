/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:39:39 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 17:42:58 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play_swap.h"

static void move(char *cmd, t_info *s, bool *show_index)
{
	int moves = open("moves.txt", O_WRONLY | O_APPEND | O_CREAT, 0664);
	if(ft_strcmp(cmd, "pa") == 0)
		pa(s, moves);
	else if(ft_strcmp(cmd, "pb") == 0)
		pb(s, moves);
	else if(ft_strcmp(cmd, "sa") == 0)
		sa(s, moves);
	else if(ft_strcmp(cmd, "sb") == 0)
		sb(s, moves);
	else if(ft_strcmp(cmd, "ss") == 0)
		ss(s, moves);
	else if(ft_strcmp(cmd, "ra") == 0)
		ra(s, moves);
	else if(ft_strcmp(cmd, "rb") == 0)
		rb(s, moves);
	else if(ft_strcmp(cmd, "rr") == 0)
		rr(s, moves);
	else if(ft_strcmp(cmd, "rra") == 0)
		rra(s, moves);
	else if(ft_strcmp(cmd, "rrb") == 0)
		rrb(s, moves);
	else if(ft_strcmp(cmd, "rrr") == 0)
		rrr(s, moves);
	else if (ft_strcmp(cmd, "i") == 0)
	{
		if (*show_index == true)
			*show_index = false;
		else
			*show_index = true;
	}
	close(moves);
}

static void	ft_play(t_info *s)
{
	char	cmd[4];
	bool	show_index;	
	int		moves;

	//ft_validate_args(argc, argv);	

	cmd[0] = 0;
	show_index = false;
	moves = open("moves.txt", O_WRONLY | O_TRUNC | O_CREAT, 0664);
	close(moves);	
	while (ft_strcmp(cmd, "q") != 0)
	{
		system("clear");
		ft_play_print(&(s->a), &(s->b), &show_index);
		if (show_index == false)
			ft_printf("( " GREEN "pa pb " CYAN "sa sb ss " MAGENTA "ra rb rr " BRIGHT_GREEN "rra rrb rrr " RESET ") (\"i\" show index, \"q\" quit)\n\n");
		if (show_index == true)
			ft_printf("( " GREEN "pa pb " CYAN "sa sb ss " MAGENTA "ra rb rr " BRIGHT_GREEN "rra rrb rrr " RESET ") (\"i\" hide index, \"q\" quit)\n\n");
		ft_printf("type a command: ");
		scanf("%3s", cmd);
		move(cmd, s, &show_index);
		fflush(stdin);
		system("clear");
	}
}

int	main(int argc, char *argv[])
{
	t_info	*s;

	s = malloc(sizeof(t_info));

	//incomplete and not tested.
	ft_validate_args(argc, argv);	

	ft_init_stacks(s, argc, argv);

	ft_play(s);

	free(s);
}
