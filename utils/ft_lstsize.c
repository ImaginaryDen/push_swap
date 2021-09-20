#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	if (!lst)
		return (0);
	return (1 + ft_lstsize(lst->next));
}
