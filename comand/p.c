#include "push_swap.h"

void	p(t_stack **out, t_stack **in)
{
	t_stack	*temp;

	if (*out == NULL)
		return ;
	temp = *out;
	*out = temp->next;
	temp->next = NULL;
	ft_lstadd_front(in, temp);
}

int	pa(t_stack **a, t_stack **b)
{
	p(b, a);
	return (PA);
}

int	pb(t_stack **a, t_stack **b)
{
	p(a, b);
	return (PB);
}
