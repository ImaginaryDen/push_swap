#include "push_swap.h"

int	exit_error(t_stack **a, t_stack **b, int flag)
{
	if (a)
		ft_lstclear(a);
	if (b)
		ft_lstclear(b);
	if (flag)
		ft_putstr_fd("Error\n", 1);
	return (1);
}
