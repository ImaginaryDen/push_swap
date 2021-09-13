#include "push_swap.h"

int check_first(t_stack *stack, int next)
{
	if (stack != NULL && stack->order == next)
		return (1);
	return (0);
}

int check_second(t_stack *stack, int next)
{
	if (stack != NULL && stack->next != NULL && stack->next->order == next)
		return (1);
	return (0);
}

int check_last(t_sort_info	*info)
{
	t_stack *temp;

	if (*info->a != NULL)
		return(0);
	temp =  ft_lstlast(*info->a);
	if( temp != NULL && temp->flag != -1 && temp->order != info->next)
		return(0);
	(*info->a)->flag = -1;
	info->next++;
	return(1);
}

int check_two_first(t_sort_info *info)
{
	return (check_first(*info->a, info->next) ||
		check_first(info->b, info->next) ||
		check_second(info->b, info->next));
}

int check_next(t_sort_info *info)
{
	int	change;

	change = 0;
	if (ft_lstsize(info->b) > 4 && ft_lstlast(info->b)->order == info->next)
		ft_lstadd_back(info->command, ft_lstnew(rrb(info->a, &info->b)));
	while(check_two_first(info))
	{
		change = 1;
		if (check_second(info->b, info->next))
		{
			if (check_first(info->b, info->next + 1))
				ft_lstadd_back(info->command, ft_lstnew(pa(info->a, &info->b)));
			else
				ft_lstadd_back(info->command, ft_lstnew(sb(info->a, &info->b)));
		}
		while (check_first(*info->a, info->next))
		{
			(*info->a)->flag = -1;
			ft_lstadd_back(info->command, ft_lstnew(ra(info->a, &info->b)));
			info->next++;
		}
		while (check_first(info->b, info->next))
		{
			info->b->flag = -1;
			ft_lstadd_back(info->command, ft_lstnew(pa(info->a, &info->b)));
			ft_lstadd_back(info->command, ft_lstnew(ra(info->a, &info->b)));
			info->next++;
		}
	}
	return (change);
}