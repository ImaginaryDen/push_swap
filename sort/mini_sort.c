#include "push_swap.h"

void	sort_three_b(t_stack **stack, t_stack **commands)
{
	const int	min = get_min(*stack);

	if (ft_lstsize(*stack) == 2)
		ft_lstadd_back(commands, ft_lstnew(sb(NULL, stack)));
	else if ((*stack)->item == min)
	{
		ft_lstadd_back(commands, ft_lstnew(rrb(NULL, stack)));
		ft_lstadd_back(commands, ft_lstnew(sb(NULL, stack)));
	}
	else if ((*stack)->next->item == min)
	{
		if ((*stack)->item < (*stack)->next->next->item)
			ft_lstadd_back(commands, ft_lstnew(sb(NULL, stack)));
		else
			ft_lstadd_back(commands, ft_lstnew(rb(NULL, stack)));
	}
	else if ((*stack)->item < (*stack)->next->item)
		ft_lstadd_back(commands, ft_lstnew(rrb(NULL, stack)));
	else
	{
		ft_lstadd_back(commands, ft_lstnew(sb(NULL, stack)));
		ft_lstadd_back(commands, ft_lstnew(rrb(NULL, stack)));
	}
}

void	sort_three(t_stack **stack, t_stack **commands)
{
	const int	min = get_min(*stack);

	if (ft_lstsize(*stack) == 2)
		ft_lstadd_back(commands, ft_lstnew(sa(stack, NULL)));
	else if ((*stack)->item == min)
	{
		ft_lstadd_back(commands, ft_lstnew(rra(stack, NULL)));
		ft_lstadd_back(commands, ft_lstnew(sa(stack, NULL)));
	}
	else if ((*stack)->next->item == min)
	{
		if ((*stack)->item < (*stack)->next->next->item)
			ft_lstadd_back(commands, ft_lstnew(sa(stack, NULL)));
		else
			ft_lstadd_back(commands, ft_lstnew(ra(stack, NULL)));
	}
	else if ((*stack)->item < (*stack)->next->item)
		ft_lstadd_back(commands, ft_lstnew(rra(stack, NULL)));
	else
	{
		ft_lstadd_back(commands, ft_lstnew(sa(stack, NULL)));
		ft_lstadd_back(commands, ft_lstnew(rra(stack, NULL)));
	}
}

void	ft_merge(t_stack **a, t_stack **b, t_stack **commands)
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
	while ((*a)->item != get_min(*a))
		ft_lstadd_back(commands, ft_lstnew(ra(a, b)));
}

void	mini_sort(t_stack **a, t_stack **commands)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstsize(*a) == 2)
	{
		ft_lstadd_back(commands, ft_lstnew(sa(a, &b)));
		return ;
	}
	while (ft_lstsize(*a) > 3)
		ft_lstadd_back(commands, ft_lstnew(pb(a, &b)));
	if (!ft_is_sort(*a, NULL))
		sort_three(a, commands);
	if (b != NULL)
	{
		if (ft_lstsize(b) != 1 && ft_is_sort(b, NULL) != 1)
			sort_three_b(&b, commands);
		ft_merge(a, &b, commands);
	}
}
