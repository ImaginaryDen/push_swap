#include "push_swap.h"

void	print_commands(t_stack *commands)
{
	const char	name[12][4] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	while (commands)
	{
		ft_putstr_fd((char *)name[commands->item], 1);
		ft_putstr_fd("\n", 1);
		commands = commands->next;
	}
}

int	ft_is_sort(t_stack *a, t_stack *b)
{
	while (a->next)
	{
		if (a->item > a->next->item || b != NULL)
			return (0);
		a = a->next;
	}
	return (1);
}

void	init_arr(int (**arr)(t_stack **, t_stack **))
{
	arr[SA] = sa;
	arr[SB] = sb;
	arr[SS] = ss;
	arr[PA] = pa;
	arr[PB] = pb;
	arr[RA] = ra;
	arr[RB] = rb;
	arr[RR] = rr;
	arr[RRA] = rra;
	arr[RRB] = rrb;
	arr[RRR] = rrr;
}

int	ft_check(t_stack **a, t_stack *com)
{
	t_stack		*b;
	int			(*all_funcs[11])(t_stack	**,	t_stack	**);

	b = NULL;
	init_arr(all_funcs);
	while (com != NULL)
	{
		all_funcs[com->item](a, &b);
		com = com->next;
	}
	if (ft_is_sort(*a, b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}
