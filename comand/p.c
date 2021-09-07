#include "push_swap.h"

void p(t_stack **out, t_stack **in)
{
	t_stack *temp;

	temp = *out;
	*out = temp->next;
	temp->next = NULL;
	ft_lstadd_front(in, temp);
}

void pa(t_stack **a, t_stack **b)
{
	p(a, b);
	print_comand("pa", *a, *b);
}

void pb(t_stack **a, t_stack **b)
{
	p(b, a);
	print_comand("pb", *a, *b);
}