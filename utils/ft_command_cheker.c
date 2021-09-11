#include "push_swap.h"


void    ft_del_next(t_stack **stack, t_stack **command)
{
    t_stack *temp;

    temp = (*stack)->next;
    (*stack)->next = (*stack)->next->next;
    free(temp);
    *stack = *command;
}

void    ft_command_cheker(t_stack **command)
{
    t_stack *temp;

    temp = *command;
    while (temp->next)
    {
        if ((temp->item == SA && temp->next->item == SB) || (temp->item == SB && temp->next->item == SA))
        {
            temp->item = SS;
            ft_del_next(&temp, command);
            continue;
        }
        if ((temp->item == RA && temp->next->item  == RB) || (temp->item == RB && temp->next->item == RA))
        {
            temp->item = RR;
            ft_del_next(&temp, command);
            continue;
        }
        if ((temp->item == RRA && temp->next->item  == RRB) || (temp->item == RRB && temp->next->item == RRA))
        {
            temp->item = RRR;
            ft_del_next(&temp, command);
            continue;
        }
        temp = temp->next;
    }
}