#include "push_swap.h"

void print_info(t_for_sort info)
{
	ft_putstr_fd("MID ", 1);
	ft_putnbr_fd(info.mid, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("MAX ", 1);
	ft_putnbr_fd(info.max, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("NEXT ", 1);
	ft_putnbr_fd(info.next, 1);
	ft_putchar_fd('\n', 1);
}

int		less(t_stack *stack,  int mid)
{
	while(stack)
	{
		if (stack->order < mid)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	div_stack(t_stack **a, t_stack **b, t_stack **comand, t_for_sort sort_info)
{
	while(less(*a, sort_info.mid))
	{
		while ((*a)->order > sort_info.mid)
		{
			ra(a, b);
			ft_lstadd_back(comand, ft_lstnew(RA));
		}
		pb(a, b);
		ft_lstadd_back(comand, ft_lstnew(PB));
	}
}

void	ft_sort_stack(t_stack **a, t_stack **comands)
{
	t_stack *b;
	t_for_sort sort_info;

	sort_info.next = 1;
	sort_info.max = ft_lstsize(*a);
	sort_info.mid = sort_info.max / 2 + sort_info.next;
	print_info(sort_info);
	div_stack(a, &b, comands, sort_info);
}