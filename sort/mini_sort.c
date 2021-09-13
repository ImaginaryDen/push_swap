#include "push_swap.h"

int get_min(t_stack *stack)
{
	int min;

	min = stack->item;
	while (stack)
	{
		if (stack->item < min)
			min = stack->item;
		stack = stack->next;
	}
	return (min);
}

int get_max(t_stack *stack)
{
	int max;

	max = stack->item;
	while (stack)
	{
		if (stack->item > max)
			max = stack->item;
		stack = stack->next;
	}
	return (max);
}

void sort_three_b(t_stack **stack, t_stack **commands)
{
	int min;

	if (ft_is_sort(*stack))
		return ;
	if (ft_lstsize(*stack) == 2)
	{
		ft_lstadd_back(commands, ft_lstnew(sb(NULL, stack)));
		return ;
	}
	min = get_min(*stack);
	if ((*stack)->item == min)
	{
		ft_lstadd_back(commands, ft_lstnew(rrb(NULL, stack)));
		ft_lstadd_back(commands, ft_lstnew(sb(NULL, stack)));
	}else if((*stack)->next->item == min)
	{
		if ((*stack)->item < (*stack)->next->next->item)
			ft_lstadd_back(commands, ft_lstnew(sb(NULL, stack)));
		else
			ft_lstadd_back(commands, ft_lstnew(rb(NULL, stack)));
	}else if ((*stack)->item < (*stack)->next->item)
		ft_lstadd_back(commands, ft_lstnew(rrb(NULL, stack)));
	else
	{
		ft_lstadd_back(commands, ft_lstnew(sb(NULL, stack)));
		ft_lstadd_back(commands, ft_lstnew(rrb(stack, NULL)));
	}
}

void sort_three(t_stack **stack, t_stack **commands)
{
	int min;

	if (ft_is_sort(*stack))
		return ;
	if (ft_lstsize(*stack) == 2 && ft_is_sort(*stack))
	{
		ft_lstadd_back(commands, ft_lstnew(sa(stack, NULL)));
		return ;
	}
	min = get_min(*stack);
	if ((*stack)->item == min)
	{
		ft_lstadd_back(commands, ft_lstnew(rra(stack, NULL)));
		ft_lstadd_back(commands, ft_lstnew(sa(stack, NULL)));
	}else if((*stack)->next->item == min)
	{
		if ((*stack)->item < (*stack)->next->next->item)
			ft_lstadd_back(commands, ft_lstnew(sa(stack, NULL)));
		else
			ft_lstadd_back(commands, ft_lstnew(ra(stack, NULL)));
	}else if ((*stack)->item < (*stack)->next->item)
		ft_lstadd_back(commands, ft_lstnew(rra(stack, NULL)));
	else
	{
		ft_lstadd_back(commands, ft_lstnew(sa(stack, NULL)));
		ft_lstadd_back(commands, ft_lstnew(rra(stack, NULL)));
	}
}

void ft_merge(t_stack **a, t_stack **b, t_stack **commands)
{
	while (*b != NULL)
	{
		if ((*b)->item > get_max(*a) && (*a)->item == get_min(*a))
			ft_lstadd_back(commands, ft_lstnew(pa(a, b)));
		if ((*b) != NULL && (*a)->item > (*b)->item)
			ft_lstadd_back(commands, ft_lstnew(pa(a, b)));
		else
			ft_lstadd_back(commands, ft_lstnew(ra(a, b)));
	}
	while((*a)->item != get_min(*a))
		ft_lstadd_back(commands, ft_lstnew(ra(a, b)));
}

void mini_sort(t_stack **a,  t_stack **commands)
{
	t_stack *b;

	b = NULL;
	if (ft_lstsize(*a) == 2)
	{
		ft_lstadd_back(commands, ft_lstnew(sa(a, &b)));
		return ;
	}
	while (ft_lstsize(*a) > 3)
		ft_lstadd_back(commands, ft_lstnew(pb(a, &b)));
	sort_three(a, commands);
	if (b != NULL)
	{
		if (ft_lstsize(b) != 1)
			sort_three_b(&b, commands);
		ft_merge(a, &b, commands);
	}
}