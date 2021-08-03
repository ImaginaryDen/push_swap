#include "push_swap.h"

void print_stack(t_stack *a, t_stack *b)
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
		ft_putchar_fd(' ', 1);
		if (b)
		{
			ft_putnbr_fd(b->item, 1);
			b = b->next;
		}
		ft_putchar_fd('\n', 1);
	}
}

void print_comand(char *head, t_stack *a, t_stack *b)
{
	if (TYPE_OUTPUT == 0)
		return ;
	if (TYPE_OUTPUT == 1)
	{
		ft_putstr_fd(head, 1);
		ft_putchar_fd(' ', 1);
		return;
	}
	ft_putstr_fd("----------------------------------------------------------------------------------------------------------\n", 1);
	ft_putstr_fd(head, 1);
	ft_putstr_fd(":\n", 1);
	print_stack(a, b);
	ft_putstr_fd("_ _\na b\n", 1);
}