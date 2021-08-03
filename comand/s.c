#include "push_swap.h"

void s(t_stack **stack)
{
	t_stack *stack_prev;

	if (!*stack || !(*stack)->next)
		return ;
	stack_prev = (*stack)->next;
	(*stack)->next = stack_prev->next;
	stack_prev->prev = (*stack)->prev;
	(*stack)->prev = stack_prev;
	stack_prev->next = (*stack); 
	*stack = stack_prev;
}

void sa(t_stack **a, t_stack **b)
{
	(void)b;
	s(a);
	print_comand("sa", *a, *b);
}

void sb(t_stack **a, t_stack **b)
{
	(void)a;
	s(b);
	print_comand("sb", *a, *b);
}

void ss(t_stack **a, t_stack **b)
{
	s(a);
	s(b);
	print_comand("ss", *a, *b);
}