#include "../../libft.h"

static bool ft_check_int_reverse_2(t_dll **tail, int offset)
{
	t_dll *trav;
	int	val_min;
	int	val_max;
	int	curr;
	int	next;

	trav = *tail;
	val_min = *(int *)((char *)ft_dclst_find_lowest_int(tail, offset) + offset);
	val_max = *(int *)((char *)ft_dclst_find_highest_int(tail, offset) + offset);
	while (1)
	{
		curr = *(int *)((char *)trav + offset);
		next = *(int *)((char *)trav->next + offset);

		if (curr == val_min)
		{
			if (next != val_max)
				return (false);
		}
		else
		{
			if (next != curr - 1)
				return (false);
		}
		trav = trav->next;
		if (trav == *tail)
			break ;
	}
	return (true);
}


static bool ft_check_int_normal_2(t_dll **tail, int offset)
{
	t_dll *trav;
	int	val_min;
	int	val_max;
	int	curr;
	int	next;

	trav = *tail;
	val_min = *(int *)((char *)ft_dclst_find_lowest_int(tail, offset) + offset);
	val_max = *(int *)((char *)ft_dclst_find_highest_int(tail, offset) + offset);
	while (1)
	{
		curr = *(int *)((char *)trav + offset);
		next = *(int *)((char *)trav->next + offset);

		if (curr == val_max)
		{
			if (next != val_min)
				return (false);
		}
		else
			if (next != curr + 1)
				return (false);
		trav = trav->next;
		if (trav == *tail)
			break ;
	}
	return (true);
}

/* type i-int | modes n-normal, r-reverse | offssetof(struct, variable)*/
bool ft_dclst_clock_sortd(t_dll **tail, char mode, int offset)
{
	if (mode == 'n')
		return (ft_check_int_normal_2(tail, offset));
	else if (mode == 'r')
		return (ft_check_int_reverse_2(tail, offset));
	else
		ft_perror_exit("ft_dclst_clock_sortd_len: invalid mode", 1); /// IMPROVE ERROR
	return (false);
}
