#include "push_swap.h"

t_stack	*ft_lstcopy(t_stack *stack)
{
	t_stack	*copy_stack;

	copy_stack = NULL;
	while (stack)
	{
		ft_lstadd_back(&copy_stack, ft_lstnew(stack->item));
		stack = stack->next;
	}
	return (copy_stack);
}
