#include "push_swap.h"

void print_info(t_for_sort info)
{
	ft_putstr_fd("------\nMID ", 1);
	ft_putnbr_fd(info.mid, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("MAX ", 1);
	ft_putnbr_fd(info.max, 1);
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("NEXT ", 1);
	ft_putnbr_fd(info.next, 1);
	ft_putstr_fd("\n------\n", 1);
}

int less(t_stack *a, int b)
{
	return (a->order <= b && a->flag != -1);
}

int larger(t_stack *a, int b)
{
	return (a->order >= b);
}

int		if_there_is(t_stack *stack,  int mid, int (*compare)(t_stack *, int))
{
	while(stack)
	{
		if (compare(stack, mid))
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	div_stack(t_for_sort *sort_info, t_stack **out, int (*compare)(t_stack *, int))
{
	while(if_there_is(*out, sort_info->mid, compare))
	{
		if (sort_info->b != NULL && sort_info->b->order == sort_info->next
			&& *out == sort_info->b)
		{
			sort_info->b->flag = -1;
			pa(sort_info->a, &sort_info->b);
			ft_lstadd_back(sort_info->command, ft_lstnew(PA));
			ra(sort_info->a, &sort_info->b);
			ft_lstadd_back(sort_info->command, ft_lstnew(RA));
			sort_info->next++;
			continue;
		}
		while (!compare((*out), sort_info->mid))
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

void check_next(t_for_sort *sort_info)
{
	while((*sort_info->a)->order == sort_info->next || (sort_info->b != NULL && sort_info->b->order == sort_info->next))
	{
		while ((*sort_info->a)->order == sort_info->next)
		{
			(*sort_info->a)->flag = -1;
			ra(sort_info->a, &sort_info->b);
			ft_lstadd_back(sort_info->command, ft_lstnew(RA));
			sort_info->next++;
		}
		while (sort_info->b != NULL && sort_info->b->order == sort_info->next)
		{
			sort_info->b->flag = -1;
			pa(sort_info->a, &sort_info->b);
			ra(sort_info->a, &sort_info->b);
			ft_lstadd_back(sort_info->command, ft_lstnew(PA));
			ft_lstadd_back(sort_info->command, ft_lstnew(RA));
			sort_info->next++;
		}
	}
}

int is_sort(t_for_sort *sort_info)
{
	t_stack *temp;

	temp = *(sort_info->a);
	while (temp)
	{
		if (temp->flag == -1)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	ft_sort_stack(t_stack **a, t_stack **comands)
{
	t_for_sort	sort_info;
	int			size;

	size  = ft_lstsize(*a);
	sort_info.next = 1;
	sort_info.a = a;
	sort_info.b = NULL;
	sort_info.command = comands;
	sort_info.flag = sort_info.next;
	while ((*sort_info.a)->flag != -1 )
	{
		sort_info.max = size;
		sort_info.mid = ((sort_info.max - sort_info.next) / 2) + sort_info.next;
		div_stack(&sort_info, sort_info.a, less);
		sort_info.max = sort_info.mid;
		if (is_sort(&sort_info))
			while (ft_lstlast(*sort_info.a)->flag != -1 || (*sort_info.a)->flag == -1)
			{
				rra(sort_info.a, &sort_info.b);
				ft_lstadd_back(comands, ft_lstnew(RRA));
			}
		while (sort_info.b != NULL)
		{
			sort_info.mid = ((sort_info.max - sort_info.next) / 2) + sort_info.next;
			sort_info.flag++;
			div_stack(&sort_info, &sort_info.b, larger);
			check_next(&sort_info);
			if (sort_info.b != NULL)
			{
				sort_info.max = sort_info.mid;
				continue;
			}
			while ((*sort_info.a)->flag != 0 && (*sort_info.a)->flag != -1)
			{
				pb(sort_info.a, &sort_info.b);
				ft_lstadd_back(comands, ft_lstnew(PB));
			}
		}
	}
}