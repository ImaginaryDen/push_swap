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
	return (a <= b);
}

int larger(int a, int b)
{
	return (a >= b);
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

void	div_stack(t_for_sort *sort_info, t_stack **out, int (*compare)(int, int))
{
	while(if_there_is(*out, sort_info->mid, compare))
	{
		if (sort_info->b != NULL && sort_info->b->order == sort_info->next)
		{
			pa(sort_info->a, &sort_info->b);
			ft_lstadd_back(sort_info->command, ft_lstnew(PA));
			ra(sort_info->a, &sort_info->b);
			ft_lstadd_back(sort_info->command, ft_lstnew(RA));
			sort_info->next++;
			continue;
		}
		while (!compare((*out)->order, sort_info->mid))
		{
			if (out == sort_info->a)
			{
				ra(sort_info->a, &sort_info->b);
				ft_lstadd_back(sort_info->command, ft_lstnew(RA));
				continue;
			}
			rb(sort_info->a, &sort_info->b);
			ft_lstadd_back(sort_info->command, ft_lstnew(RB));
		}
		if (out == sort_info->a)
		{
			pb(sort_info->a, &sort_info->b);
			ft_lstadd_back(sort_info->command, ft_lstnew(PB));
			continue;
		}
		sort_info->b->flag = sort_info->flag;
		pa(sort_info->a, &sort_info->b);
		ft_lstadd_back(sort_info->command, ft_lstnew(PA));
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
	sort_info.flag = sort_info.next;
	print_info(sort_info);
	div_stack(&sort_info, sort_info.a, less);
	sort_info.max = sort_info.mid;
	sort_info.mid = sort_info.max / 2 + sort_info.next;
	print_info(sort_info);
	div_stack(&sort_info, &sort_info.b, larger);
}