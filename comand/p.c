#include "push_swap.h"

void	p(t_stack **out, t_stack **in)
{
	t_stack	*temp;

	temp = *out;
	*out = temp->next;
	temp->next = NULL;
	ft_lstadd_front(in, temp);
}

void	pa(t_stack **a, t_stack **b)
{
	p(a, b);
}

void	pb(t_stack **a, t_stack **b)
{
	p(b, a);
}
