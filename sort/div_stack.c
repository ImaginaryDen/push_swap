#include "push_swap.h"

int	if_there_is(t_stack *stack, int mid, int (*compare)(t_stack *, int))
{
	while (stack)
	{
		if (compare(stack, mid))
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	div_stack(t_sort_info *inf, t_stack **out,
	int (*compare)(t_stack *, int))
{
	while (if_there_is(*out, inf->mid, compare))
	{
		if (*out == inf->b && check_next(inf))
			continue ;
		while (!compare((*out), inf->mid))
		{
			if (out == inf->a)
				ft_lstadd_back(inf->command, ft_lstnew(ra(inf->a, &inf->b)));
			else
				ft_lstadd_back(inf->command, ft_lstnew(rb(inf->a, &inf->b)));
		}
		if (out == inf->a)
		{
			ft_lstadd_back(inf->command, ft_lstnew(pb(inf->a, &inf->b)));
			continue ;
		}
		inf->b->flag = inf->flag;
		ft_lstadd_back(inf->command, ft_lstnew(pa(inf->a, &inf->b)));
	}
}
