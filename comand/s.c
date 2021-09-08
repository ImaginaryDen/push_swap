#include "push_swap.h"

void s(t_stack **stack)
{
	t_stack *stack_next;

	if (!*stack || !(*stack)->next)
		return ;
	stack_next = (*stack)->next;
	(*stack)->next = stack_next->next;
	stack_next->next = (*stack); 
	*stack = stack_next;
}

void sa(t_stack **a, t_stack **b)
{
	(void)b;
	s(a);
}

void sb(t_stack **a, t_stack **b)
{
	(void)a;
	s(b);
}

void ss(t_stack **a, t_stack **b)
{
	s(a);
	s(b);
}