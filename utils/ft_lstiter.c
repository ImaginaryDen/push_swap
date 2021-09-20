#include "push_swap.h"

void	ft_lstiter(t_stack *lst, void (*f)(int))
{
	while (lst)
	{
		f(lst->item);
		lst = lst->next;
	}
}
