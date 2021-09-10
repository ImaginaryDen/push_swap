#include "push_swap.h"

int ft_check(t_stack *a, t_stack *com)
{
	t_stack		*b;
	int			size;
	const char	name[12][4] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};
	void		(*const all_funcs[11])(t_stack	**,	t_stack	**) =
		{sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};

	size = ft_lstsize(com);
	b = NULL;
	if (com == NULL)
		ft_putstr_fd("NO COMANDS\n", 1);
	while (com != NULL)
	{
		all_funcs[com->item](&a, &b);
		ft_putstr_fd("a\tb\n", 1);
		ft_putstr_fd((char *)name[com->item], 1);
		ft_putchar_fd('\n', 1);
		ft_print_stack(a, b);
		ft_putstr_fd("----------\n", 1);
		com = com->next;
	}
	ft_putnbr_fd(size, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
