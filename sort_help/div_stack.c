#include "push_swap.h"

int		if_there_is(t_stack *stack,  int mid, int (*compare)(t_stack *, int))
{
	while(stack)
	{
		if (compare(stack, mid))
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	div_stack(t_for_sort *s_i, t_stack **out, int (*compare)(t_stack *, int))
{
	while(if_there_is(*out, s_i->mid, compare))
	{
		if (*out == s_i-> b && check_first(s_i->b, s_i->next))
		{
			s_i->b->flag = -1;
			ft_lstadd_back(s_i->command, ft_lstnew(pa(s_i->a, &s_i->b)));
			ft_lstadd_back(s_i->command, ft_lstnew(ra(s_i->a, &s_i->b)));
			s_i->next++;
			continue;
		}
		while (!compare((*out), s_i->mid))
		{
			if (out == s_i->a)
				ft_lstadd_back(s_i->command, ft_lstnew(ra(s_i->a, &s_i->b)));
			else
				ft_lstadd_back(s_i->command, ft_lstnew(rb(s_i->a, &s_i->b)));
		}
		if (out == s_i->a)
		{
			ft_lstadd_back(s_i->command, ft_lstnew(pb(s_i->a, &s_i->b)));
			continue;
		}
		s_i->b->flag = s_i->flag;
		ft_lstadd_back(s_i->command, ft_lstnew(pa(s_i->a, &s_i->b)));
	}
}