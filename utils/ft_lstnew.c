#include "push_swap.h"

t_stack 	*ft_lstnew(int item)
{
	t_stack 	*new_lst;

	new_lst = malloc(sizeof(t_stack));
	if (!new_lst)
		return (NULL);
	new_lst->item = item;
	new_lst->next = NULL;
	return (new_lst);
}
