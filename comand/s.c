#include "push_swap.h"

void	s(t_stack **stack)
{
	t_stack	*stack_next;

	if (!*stack || !(*stack)->next)
		return ;
	stack_next = (*stack)->next;
	(*stack)->next = stack_next->next;
	stack_next->next = (*stack);
	*stack = stack_next;
}

int	sa(t_stack **a, t_stack **b)
{
	(void)b;
	s(a);
	return (SA);
}

int	sb(t_stack **a, t_stack **b)
{
	(void)a;
	s(b);
	return (SB);
}

int	ss(t_stack **a, t_stack **b)
{
	s(a);
	s(b);
	return (SS);
}
