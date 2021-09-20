#include "push_swap.h"

void	rev_r(t_stack **stack);

int	rra(t_stack **a, t_stack **b)
{
	rev_r(a);
	(void)b;
	return (RRA);
}

int	rrb(t_stack **a, t_stack **b)
{
	rev_r(b);
	(void)a;
	return (RRB);
}

int	rrr(t_stack **a, t_stack **b)
{
	rev_r(a);
	rev_r(b);
	return (RRR);
}
