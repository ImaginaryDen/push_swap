#include "push_swap.h"

int ft_is_sort(t_stack *a, t_stack *b)
{
	while (a->next)
	{
		if (a->item > a->next->item || b != NULL)
			return(0);
		a = a->next;
	}
	return(1);
}

void print_info(t_stack *a, t_stack *b, int com)
{
	const char	name[12][4] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	ft_putstr_fd("a\t\tb\n", 1);
	ft_putstr_fd((char *)name[com], 1);
	ft_putchar_fd('\n', 1);
	ft_print_stack(a, b);
	ft_putstr_fd("~~~~~~~~~\n", 1);
}

int ft_check(t_stack **a, t_stack *com)
{
	t_stack		*b;
	int			size;
	int			(*const all_funcs[11])(t_stack	**,	t_stack	**) =
		{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

	size = ft_lstsize(com);
	b = NULL;
	while (com != NULL)
	{
		all_funcs[com->item](a, &b);
		com = com->next;
	}
	ft_putnbr_fd(size, 1);
	ft_putchar_fd('\n', 1);
	if (ft_is_sort(*a, b))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}
