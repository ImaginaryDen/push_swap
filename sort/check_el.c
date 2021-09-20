#include "push_swap.h"

void	push_next(t_sort_info *inf, int flag)
{
	if (check_second(inf->b, inf->next))
	{
		if (check_first(inf->b, inf->next + 1)
			|| (flag && inf->mid < inf->b->order))
		{
			inf->b->flag = inf->flag;
			ft_lstadd_back(inf->command, ft_lstnew(pa(inf->a, &inf->b)));
		}
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

int	check_next(t_sort_info *inf, int flag)
{
	int	change;

	change = 0;
	if (inf->b != NULL && ft_lstsize(inf->b) > 4
		&& ft_lstlast(inf->b)->order == inf->next)
		ft_lstadd_back(inf->command, ft_lstnew(rrb(inf->a, &inf->b)));
	while (check_two_first(inf))
	{
		change = 1;
		push_next(inf, flag);
	}
	return (change);
}
