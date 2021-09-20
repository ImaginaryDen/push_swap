#include "push_swap.h"

int	is_sort(t_sort_info *info)
{
	int		order;
	t_stack	*temp;

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

void	info_init(t_sort_info *info, t_stack **a, t_stack **commands)
{
	info->size = ft_lstsize(*a);
	info->next = 1;
	info->mid = 0;
	info->a = a;
	info->b = NULL;
	info->command = commands;
	info->flag = 1;
}

void	flag_div(t_sort_info *info)
{
	int			flag_now;
	t_stack		*temp;

	flag_now = (*info->a)->flag;
	while ((*info->a)->flag > 0 && (*info->a)->flag == flag_now)
	{
		ft_lstadd_back(info->command, ft_lstnew(pb(info->a, &info->b)));
		check_next(info, 0);
		if (info->b == NULL)
			flag_now = (*info->a)->flag;
	}
	temp = info->b;
	info->max = 0;
	while (temp)
	{
		if (temp->order > info->max)
			info->max = temp->order;
		temp = temp->next;
	}
}

void	check_flag_a(t_sort_info *info)
{
	while (info->b != NULL)
	{
		info->mid = ((info->max - info->next) / 2) + info->next;
		info->flag++;
		div_stack(info, &info->b, larger);
		check_next(info, 1);
		info->max = info->mid;
		if (info->b == NULL)
			flag_div(info);
	}
}

void	ft_sort_stack(t_stack **a, t_stack **commands, int magic_num)
{
	t_sort_info	info;

	ft_sort(*a);
	info_init(&info, a, commands);
	while ((*info.a)->flag != -1)
	{
		info.max = info.size;
		if (info.mid)
			info.mid = ((info.max - info.next) / 2) + info.next;
		else
			info.mid = (info.max / 2) + magic_num;
		div_stack(&info, info.a, less);
		info.max = info.mid;
		is_sort(&info);
		check_flag_a(&info);
	}
	ft_lstclear(&info.b);
}
