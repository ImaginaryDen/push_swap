#include "push_swap.h"

void	r(t_stack **stack)
{
	t_stack *temp;
	
	temp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
}

void	rev_r(t_stack **stack)
{
	t_stack *temp;

	if (*stack == NULL ||(*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_lstadd_front(stack, temp->next);
	temp->next = NULL;
}

void	ra(t_stack **a, t_stack **b)
{
	r(a);
	(void)b;
	print_comand("ra", *a, *b);
}

void	rb(t_stack **a, t_stack **b)
{
	r(b);
	(void)a;
	print_comand("rb", *a, *b);
}

void	rr(t_stack **a, t_stack **b)
{
	r(a);
	r(b);
	(void)a;
	print_comand("rr", *a, *b);
}

void	rra(t_stack **a, t_stack **b)
{
	rev_r(a);
	(void)b;
	print_comand("rra", *a, *b);
}

void	rrb(t_stack **a, t_stack **b)
{
	rev_r(b);
	(void)a;
	print_comand("rrb", *a, *b);
}