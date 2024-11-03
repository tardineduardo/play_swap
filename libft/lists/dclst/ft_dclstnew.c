#include "../../libft.h"

t_dll	*ft_dclstnew(void *content)
{
	t_dll	*temp;

	temp = malloc(sizeof(t_dll));
	if (!temp)
		return (NULL);
	temp->content = content;
	temp->next = temp;
	temp->prev = temp;
	return (temp);
}
