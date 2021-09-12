#include "push_swap.h"


void    ft_del_next(t_stack **stack)
{
    t_stack *temp;

    temp = (*stack)->next;
    (*stack)->next = (*stack)->next->next;
    free(temp);
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
            ft_del_next(&temp);
            continue;
        }
        if ((temp->item == RA && temp->next->item  == RB) || (temp->item == RB && temp->next->item == RA))
        {
            temp->item = RR;
            ft_del_next(&temp);
            continue;
        }
        if ((temp->item == RRA && temp->next->item  == RRB) || (temp->item == RRB && temp->next->item == RRA))
        {
            temp->item = RRR;
            ft_del_next(&temp);
            continue;
        }
        if  (temp->next->next != NULL &&
            ((temp->next->item == PA && temp->next->next->item  == PB) 
            || (temp->next->item == PB && temp->next->next->item == PA)))
        {
            ft_del_next(&temp);
            ft_del_next(&temp);
            continue;
        }
        temp = temp->next;
    }
}