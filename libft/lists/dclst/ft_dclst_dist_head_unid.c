#include "../../libft.h"

int	ft_dclst_dist_head_unid(t_dll **tail, t_dll *nd, char mode)
{
	int		i;
	int		llen;
	t_dll	*trav;

	if (!tail || !(*tail))
		return (0);
	i = 0;
	trav = nd;
	llen = ft_dclstsize(tail);
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