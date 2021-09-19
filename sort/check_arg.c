#include "push_swap.h"

int	check_arg(char *arg, t_stack *a, int *num)
{
	*num = 0;
	while (arg[*num] == '-' || arg[*num] == '+' )
		(*num)++;
	while (arg[*num])
	{
		if (!ft_isdigit(arg[*num]))
			return (0);
		(*num)++;
	}
	*num = ft_atoi(arg);
	if ((*num == -1 && arg[2] != '\0') || (*num == 0 && (arg[1] != '\0'
				|| !ft_isdigit(arg[0]))))
		return (0);
	while (a)
	{
		if (*num == a->item)
			return (0);
		a = a->next;
	}
	return (1);
}

int	check_first(t_stack *stack, int next)
{
	if (stack != NULL && stack->order == next)
		return (1);
	return (0);
}

int	check_second(t_stack *stack, int next)
{
	if (stack != NULL && stack->next != NULL && stack->next->order == next)
		return (1);
	return (0);
}

int	check_last(t_sort_info	*info)
{
	t_stack	*temp;

	if (*info->a != NULL)
		return (0);
	temp = ft_lstlast(*info->a);
	if (temp != NULL && temp->flag != -1 && temp->order != info->next)
		return (0);
	(*info->a)->flag = -1;
	info->next++;
	return (1);
}

int	check_two_first(t_sort_info *info)
{
	return (check_first(*info->a, info->next)
		|| check_first(info->b, info->next)
		|| check_second(info->b, info->next));
}
