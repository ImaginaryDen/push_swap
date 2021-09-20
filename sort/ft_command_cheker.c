#include "push_swap.h"

void	ft_del_next(t_stack **stack)
{
	t_stack	*temp;

	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	free(temp);
}

void	set_com(int command, t_stack **com, t_stack *temp)
{
	(*com)->item = command;
	ft_del_next(com);
	*com = temp;
}

void	ft_command_cheker(t_stack *com)
{
	t_stack	*temp;

	temp = com;
	while (com->next)
	{
		if (com->next->next != NULL
			&& ((com->next->item == PA && com->next->next->item == PB)
				|| (com->next->item == PB && com->next->next->item == PA)))
		{
			ft_del_next(&com);
			ft_del_next(&com);
			com = temp;
			continue ;
		}
		if ((com->item == SA && com->next->item == SB)
			|| (com->item == SB && com->next->item == SA))
			set_com(SS, &com, temp);
		if ((com->item == RA && com->next->item == RB)
			|| (com->item == RB && com->next->item == RA))
			set_com(RR, &com, temp);
		if ((com->item == RRA && com->next->item == RRB)
			|| (com->item == RRB && com->next->item == RRA))
			set_com(RRR, &com, temp);
		com = com->next;
	}
}
