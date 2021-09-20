#include "push_swap.h"

int	less(t_stack *a, int b)
{
	if (a == NULL)
		return (0);
	return (a->order <= b && a->flag != -1);
}

int	larger(t_stack *a, int b)
{
	if (a == NULL)
		return (0);
	return (a->order >= b);
}

void	rev_stack(t_sort_info *info, int order)
{
	if (order < (info->size / 2))
		while (ft_lstlast(*info->a)->flag != -1 || (*info->a)->flag == -1)
			ft_lstadd_back(info->command, ft_lstnew(rra(info->a, &info->b)));
	else
		while (ft_lstlast(*info->a)->flag != -1 || (*info->a)->flag == -1)
			ft_lstadd_back(info->command, ft_lstnew(ra(info->a, &info->b)));
}

int	get_min(t_stack *stack)
{
	int	min;

	min = stack->item;
	while (stack)
	{
		if (stack->item < min)
			min = stack->item;
		stack = stack->next;
	}
	return (min);
}

int	get_max(t_stack *stack)
{
	int	max;

	max = stack->item;
	while (stack)
	{
		if (stack->item > max)
			max = stack->item;
		stack = stack->next;
	}
	return (max);
}
