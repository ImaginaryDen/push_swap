#include "push_swap.h"

int is_sort(t_for_sort *sort_info)
{
	int		order;
	t_stack *temp;

	temp = *(sort_info->a);
	order = 0;
	while (temp)
	{
		if (temp->flag == -1)
		{
			while (temp->flag != -1)
			{
				order++;
				temp = temp->next;	
			}
			rev_stack(sort_info, order);
			return (1);
		}
		order++;
		temp = temp->next;
	}
	return (0);
}

void info_init(t_for_sort *sort_info, t_stack **a, t_stack ** commands)
{
	sort_info->size  = ft_lstsize(*a);
	sort_info->next = 1;
	sort_info->a = a;
	sort_info->b = NULL;
	sort_info->command = commands;
	sort_info->flag = 1;
	check_last(sort_info);
	check_next(sort_info);
}

void flag_div(t_for_sort *info)
{
	int			flag_now;

	flag_now = (*info->a)->flag;
	info->max = 0;
	while ((*info->a)->flag > 0 && (*info->a)->flag == flag_now)
	{
		if ((*info->a)->order > info->max)
			info->max = (*info->a)->order;
		ft_lstadd_back(info->command, ft_lstnew(pb(info->a, &info->b)));
		check_next(info);
		if (info->b == NULL)
			flag_now = (*info->a)->flag;
	}
}

void	ft_sort_stack(t_stack **a, t_stack **comands)
{
	t_for_sort	info;

	info_init(&info, a, comands);
	while ((*info.a)->flag != -1 )
	{
		info.max = info.size;
		info.mid = ((info.max - info.next) / 2) + info.next;
		div_stack(&info, info.a, less);
		info.max = info.mid;
		is_sort(&info);
		while (info.b != NULL)
		{
			info.mid = ((info.max - info.next) / 2) + info.next;
			info.flag++;
			div_stack(&info, &info.b, larger);
			check_next(&info);
			info.max = info.mid;
			if (info.b == NULL)
				flag_div(&info);
		}
	}
	ft_lstclear(&info.b);
}