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

int less(int a, int b)
{
	return (a < b);
}

int larger(int a, int b)
{
	return (a > b);
}

int		if_there_is(t_stack *stack,  int mid, int (*compare)(int, int))
{
	while(stack)
	{
		if (compare(stack->order, mid))
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	div_stack(t_for_sort *sort_info, t_stack **out, t_stack **in, int (*compare)(int, int))
{
	while(if_there_is(*out, sort_info->mid, compare))
	{
		while (!compare((*out)->order, sort_info->mid))
		{
			if (out == sort_info->a)
			{
			ft_putchar_fd('1',1);
				ra(out, in);
				ft_lstadd_back(sort_info->command, ft_lstnew(RA));
				continue;
			}
			rb(out, in);
			ft_lstadd_back(sort_info->command, ft_lstnew(RB));
		}
		if (out == sort_info->a)
		{
			pb(out, in);
			ft_lstadd_back(sort_info->command, ft_lstnew(PB));
			continue;
		}
		pa(out, in);
		ft_lstadd_back(sort_info->command, ft_lstnew(PA));
	}
}

void	mid_app(t_for_sort *sort_info,	t_stack **command)
{
	int order_mid;
	t_stack *temp;

	temp = sort_info->b;
	order_mid = 0;
	while (temp->order != sort_info->mid)
	{
		temp = temp->next;
		order_mid++;
	}
	if (order_mid < ft_lstsize(sort_info->b) / 2)
		while ((sort_info->b)->order != sort_info->mid)
		{
			rb(NULL, &(sort_info->b));
			ft_lstadd_back(command, ft_lstnew(RB));
		}
	else
		while ((sort_info->b)->order != sort_info->mid)
		{
			rrb(NULL, &(sort_info->b));
			ft_lstadd_back(command, ft_lstnew(RRB));
		}	
}

void	ft_sort_stack(t_stack **a, t_stack **comands)
{
	t_for_sort sort_info;

	sort_info.next = 1;
	sort_info.max = ft_lstsize(*a);
	sort_info.mid = sort_info.max / 2 + sort_info.next;
	sort_info.a = a;
	sort_info.b = NULL;
	sort_info.command = comands;
	print_info(sort_info);
	div_stack(&sort_info, sort_info.a, &sort_info.b, less);
	return ;
	mid_app(&sort_info, comands);
	sort_info.mid = sort_info.max / 2 + sort_info.next;
}