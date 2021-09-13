#include "push_swap.h"

int less(t_stack *a, int b)
{
	return (a->order <= b && a->flag != -1);
}

int larger(t_stack *a, int b)
{
	return (a->order >= b);
}

void rev_stack(t_sort_info *info, int order)
{
	if (order < (info->size / 2))
		while (ft_lstlast(*info->a)->flag != -1 || (*info->a)->flag == -1)
			ft_lstadd_back(info->command, ft_lstnew(rra(info->a, &info->b)));
	else
		while (ft_lstlast(*info->a)->flag != -1 || (*info->a)->flag == -1)
			ft_lstadd_back(info->command, ft_lstnew(ra(info->a, &info->b)));
}