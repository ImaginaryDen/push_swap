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

int check_next(t_sort_info *inf)
{
	int	change;

	change = 0;
	if (inf->b != NULL && ft_lstsize(inf->b) > 4 && ft_lstlast(inf->b)->order == inf->next)
		ft_lstadd_back(inf->command, ft_lstnew(rrb(inf->a, &inf->b)));
	while(check_two_first(inf))
	{
		change = 1;
		if (check_second(inf->b, inf->next))
		{
			if (check_first(inf->b, inf->next + 1))
				ft_lstadd_back(inf->command, ft_lstnew(pa(inf->a, &inf->b)));
			else
				ft_lstadd_back(inf->command, ft_lstnew(sb(inf->a, &inf->b)));
		}
		while (check_first(*inf->a, inf->next))
		{
			(*inf->a)->flag = -1;
			ft_lstadd_back(inf->command, ft_lstnew(ra(inf->a, &inf->b)));
			inf->next++;
		}
		while (check_first(inf->b, inf->next))
		{
			inf->b->flag = -1;
			ft_lstadd_back(inf->command, ft_lstnew(pa(inf->a, &inf->b)));
			ft_lstadd_back(inf->command, ft_lstnew(ra(inf->a, &inf->b)));
			inf->next++;
		}
	}
	return (change);
}