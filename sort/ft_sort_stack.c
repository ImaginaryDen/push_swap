#include "push_swap.h"

int		is_sort(t_sort_info *info)
{
	int		order;
	t_stack *temp;

	temp = *(info->a);
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
			rev_stack(info, order);
			return (1);
		}
		order++;
		temp = temp->next;
	}
	return (0);
}

void	info_init(t_sort_info *info, t_stack **a, t_stack ** commands)
{
	info->size  = ft_lstsize(*a);
	info->next = 1;
	info->a = a;
	info->b = NULL;
	info->command = commands;
	info->flag = 1;
	check_last(info);
	check_next(info);
}

void	flag_div(t_sort_info *info)
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

void	ft_sort_stack(t_stack **a, t_stack **commands)
{
	t_sort_info	info;

	if (ft_lstsize(*a) <= 6)
	{
		mini_sort(a, commands);
		return ;
	}
	ft_sort(*a);
	info_init(&info, a, commands);
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
	ft_command_cheker(*commands);
}