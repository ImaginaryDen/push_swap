#include "push_swap.h"

void	r(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	*stack = (*stack)->next;
	temp->next = NULL;
	ft_lstadd_back(stack, temp);
}

void	rev_r(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	ft_lstadd_front(stack, temp->next);
	temp->next = NULL;
}

int	ra(t_stack **a, t_stack **b)
{
	r(a);
	(void)b;
	return (RA);
}

int	rb(t_stack **a, t_stack **b)
{
	r(b);
	(void)a;
	return (RB);
}

int	rr(t_stack **a, t_stack **b)
{
	r(a);
	r(b);
	(void)a;
	return (RR);
}
