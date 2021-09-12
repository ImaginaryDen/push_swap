#include "push_swap.h"

int check_next(t_for_sort *info);
int check_first(t_stack *stack, int next);

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

void	div_stack(t_for_sort *s_i, t_stack **out, int (*compare)(t_stack *, int))
{
	while(if_there_is(*out, s_i->mid, compare))
	{
		if (*out == s_i-> b && check_first(s_i->b, s_i->next))
		{
			s_i->b->flag = -1;
			ft_lstadd_back(s_i->command, ft_lstnew(pa(s_i->a, &s_i->b)));
			ft_lstadd_back(s_i->command, ft_lstnew(ra(s_i->a, &s_i->b)));
			s_i->next++;
			continue;
		}
		while (!compare((*out), s_i->mid))
		{
			if (out == s_i->a)
				ft_lstadd_back(s_i->command, ft_lstnew(ra(s_i->a, &s_i->b)));
			else
				ft_lstadd_back(s_i->command, ft_lstnew(rb(s_i->a, &s_i->b)));
		}
		if (out == s_i->a)
		{
			ft_lstadd_back(s_i->command, ft_lstnew(pb(s_i->a, &s_i->b)));
			continue;
		}
		s_i->b->flag = s_i->flag;
		ft_lstadd_back(s_i->command, ft_lstnew(pa(s_i->a, &s_i->b)));
	}
}

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

int check_last(t_for_sort	*sort_info)
{
	t_stack *temp;

	if (*sort_info->a != NULL)
		return(0);
	temp =  ft_lstlast(*sort_info->a);
	if( temp != NULL && temp->flag != -1 && temp->order != sort_info->next)
		return(0);
	(*sort_info->a)->flag = -1;
	sort_info->next++;
	return(1);
}

int check_two_first(t_for_sort *sort_info)
{
	return (check_first(*sort_info->a, sort_info->next) ||
		check_first(sort_info->b, sort_info->next) ||
		check_second(sort_info->b, sort_info->next));
}

int check_next(t_for_sort *info)
{
	int	change;

	change = 0;
	if (ft_lstsize(info->b) > 4 && ft_lstlast(info->b)->order == info->next)
		ft_lstadd_back(info->command, ft_lstnew(rrb(info->a, &info->b)));
	while(check_two_first(info))
	{
		change = 1;
		if (check_second(info->b, info->next))
		{
			if (check_first(info->b, info->next + 1))
				ft_lstadd_back(info->command, ft_lstnew(pa(info->a, &info->b)));
			else
				ft_lstadd_back(info->command, ft_lstnew(sb(info->a, &info->b)));
		}
		while (check_first(*info->a, info->next))
		{
			(*info->a)->flag = -1;
			ft_lstadd_back(info->command, ft_lstnew(ra(info->a, &info->b)));
			info->next++;
		}
		while (check_first(info->b, info->next))
		{
			info->b->flag = -1;
			ft_lstadd_back(info->command, ft_lstnew(pa(info->a, &info->b)));
			ft_lstadd_back(info->command, ft_lstnew(ra(info->a, &info->b)));
			info->next++;
		}
	}
	return (change);
}

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
			if (order < sort_info->size / 2)
				while (ft_lstlast(*sort_info->a)->flag != -1 || (*sort_info->a)->flag == -1)
					ft_lstadd_back(sort_info->command, ft_lstnew(rra(sort_info->a, &sort_info->b)));
			else
				while (ft_lstlast(*sort_info->a)->flag != -1 || (*sort_info->a)->flag == -1)
					ft_lstadd_back(sort_info->command, ft_lstnew(ra(sort_info->a, &sort_info->b)));
			return (1);
		}
		order++;
		temp = temp->next;
	}
	return (0);
}

void	ft_sort_stack(t_stack **a, t_stack **comands)
{
	t_for_sort	sort_info;
	int			flag_now;

	sort_info.size  = ft_lstsize(*a);
	sort_info.next = 1;
	sort_info.a = a;
	sort_info.b = NULL;
	sort_info.command = comands;
	check_last(&sort_info);
	sort_info.flag = sort_info.next;
	check_next(&sort_info);
	while ((*sort_info.a)->flag != -1 )
	{
		sort_info.max = sort_info.size;
		sort_info.mid = ((sort_info.max - sort_info.next) / 2) + sort_info.next;
		div_stack(&sort_info, sort_info.a, less);
		sort_info.max = sort_info.mid;
		is_sort(&sort_info);
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
			flag_now = (*sort_info.a)->flag;
			sort_info.max = 0;
			while ((*sort_info.a)->flag > 0 && (*sort_info.a)->flag == flag_now)
			{
				if ((*sort_info.a)->order > sort_info.max)
					sort_info.max = (*sort_info.a)->order;
				ft_lstadd_back(comands, ft_lstnew(pb(sort_info.a, &sort_info.b)));
				check_next(&sort_info);
				if (sort_info.b == NULL)
					flag_now = (*sort_info.a)->flag;
			}
		}
	}
	ft_lstclear(&sort_info.b);
}