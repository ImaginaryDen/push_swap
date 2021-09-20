#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *last)
{
	if (!last)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}
