#include "push_swap.h"


void    ft_del_next(t_stack **stack)
{
	t_stack *temp;

	temp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	free(temp);
}

void    ft_command_cheker(t_stack *com)
{
	while (com->next)
	{
		if ((com->item == SA && com->next->item == SB) || (com->item == SB && com->next->item == SA))
		{
			com->item = SS;
			ft_del_next(&com);
		}
		if ((com->item == RA && com->next->item  == RB) || (com->item == RB && com->next->item == RA))
		{
			com->item = RR;
			ft_del_next(&com);
		}
		if ((com->item == RRA && com->next->item  == RRB) || (com->item == RRB && com->next->item == RRA))
		{
			com->item = RRR;
			ft_del_next(&com);
		}
		if  (com->next->next != NULL &&
			((com->next->item == PA && com->next->next->item  == PB) 
			|| (com->next->item == PB && com->next->next->item == PA)))
		{
			ft_del_next(&com);
			ft_del_next(&com);
			continue;
		}
		com = com->next;
	}
}