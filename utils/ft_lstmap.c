#include "push_swap.h"

t_stack	*ft_lstmap(t_stack *lst, int (*f)(int))
{
	t_stack	*new_lst;
	t_stack	*new_el;

	new_lst = NULL;
	while (lst)
	{
		new_el = ft_lstnew(f(lst->item));
		if (!new_el)
		{
			ft_lstclear(&new_lst);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_el);
		lst = lst->next;
	}
	return (new_lst);
}
