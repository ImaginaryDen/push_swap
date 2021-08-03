#include "push_swap.h"

void	ft_lstadd_front(t_stack  **lst, t_stack  *new)
{
	if (!lst)
		return ;
	new->next = *lst;
	if (*lst)
	{
		new->prev = (*lst)->prev;
		new->next->prev = new;
	}
	*lst = new;
}
