/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eduribei <eduribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:12:52 by eduribei          #+#    #+#             */
/*   Updated: 2024/10/27 15:38:50 by eduribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "play_swap.h"

//
//
// 			THESE VALIDATIONS ARE NOT TESTED !!!
//
//

static bool ft_args_are_integer_only(int argc, char *argv[])
{
	int	a;
	int b;

	a = 1;
	while (a < argc)
	{
		b = 0;
		while (ft_isspace(argv[a][b]))
			b++;
		if (argv[a][b] == '-' || argv[a][b] == '+')
			b++;
		while ((argv[a][b]) != 0)
		{
			if (!ft_isdigit(argv[a][b]))
				return (false);
			b++;
		}
		a++;
	}
	return (true);
}
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
// THIS IS NOT WORKING!!!!!!!!!!!!!!!!!!!!!!!!!!!
static bool ft_args_are_distinct_and_size_int(int argc, char *argv[])
{
	long long int	a;
	long long int	b;
	long long int	set[argc - 1];


	a = 0;
	while (a < argc - 1)
	{
		set[a] = ft_atoi(argv[a + 1]);
		if (set[a] > INT_MAX || set[a] < INT_MIN)
			return (false);
		b = 0;
		while (b < a)
		{
			if (set[b] == set[a])
				return (false);
			b++;
		}
	a++;
	}
	return (true);
}

static bool ft_args_are_sorted(int argc, char *argv[])
{
	int	a;
	int	curr;
	int	next;
	int	count;

	a = 1;
	count = 0;
	while (a < argc - 1)
	{
		curr = ft_atoi(argv[a]);
		next = ft_atoi(argv[a + 1]);
		if (curr > next)
			count++;
		a++;
	}
	if (count == 0)
		return (true);
	return (false);
}

static bool formatting_error(int argc, char *argv[])
{
	int	a;
	int	curr;

	a = 1;
	while (a < argc - 1)
	{
		curr = ft_atoi(argv[a]);
		if (curr > 99 || curr < -9)
			return (true);
		a++;
	}
	return (false);
}

void	ft_validate_args(int argc, char *argv[])
{
	if (argc < 3)
		ft_error_exit("Error - no parameters (use ./play 5 3 2 9 4)\n", 1);
	else if (!ft_args_are_integer_only(argc, argv))
		ft_error_exit("Error - args must be integers\n", 1);
	else if (!ft_args_are_distinct_and_size_int(argc, argv))
		ft_error_exit("Error - repeated args\n", 1);
	else if (ft_args_are_sorted(argc, argv))
		ft_error_exit("Error - already sorted\n", 1);
	else if (formatting_error(argc, argv))
		ft_error_exit("Keep numbers between -9 and 99, or box formatting will break. Sorry!\n", 1);
}
