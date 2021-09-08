#include "push_swap.h"

void	ft_print_stack(t_stack *a, t_stack *b)
{
	while(a != NULL || b != NULL)
	{
		if (a)
		{
			ft_putnbr_fd(a->item, 1);
			a = a->next;
		}
		else
			ft_putchar_fd(' ', 1);
		ft_putchar_fd('\t', 1);
		if (b)
		{
			ft_putnbr_fd(b->item, 1);
			b = b->next;
		}
		ft_putchar_fd('\n', 1);
	}
}