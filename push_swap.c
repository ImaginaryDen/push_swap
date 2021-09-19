#include "push_swap.h"

int	exit_error(t_stack **a)
{
	ft_lstclear(a);
	return (1);
}

void	print_commands(t_stack *commands)
{
	const char	name[12][4] = {"sa", "sb", "ss", "pa", "pb",
		"ra", "rb", "rr", "rra", "rrb", "rrr"};

	while (commands)
	{
		ft_putstr_fd((char *)name[commands->item], 1);
		ft_putstr_fd("\n", 1);
		commands = commands->next;
	}
}

int	find_min_magic(t_stack *stack, t_stack **commands)
{
	t_stack	*copy_stack;
	int		min;
	int		magic_min;
	int		size;
	int		max_check;

	max_check = 15;
	if (ft_lstsize(stack) < 100)
		max_check = 2;
	while (max_check)
	{
		copy_stack = ft_lstcopy(stack);
		ft_sort_stack(&copy_stack, commands, max_check);
		ft_command_cheker(*commands);
		size = ft_lstsize(*commands);
		if (!min || min > size)
		{
			min = size;
			magic_min = max_check;
		}
		ft_lstclear(&copy_stack);
		ft_lstclear(commands);
		max_check--;
	}
	return (magic_min);
}

void	find_solve(t_stack **commands, t_stack *stack)
{
	t_stack	*copy_stack;

	copy_stack = ft_lstcopy(stack);
	if (ft_lstsize(copy_stack) <= 6)
		mini_sort(&copy_stack, commands);
	else
		ft_sort_stack(&copy_stack, commands, find_min_magic(stack, commands));
	ft_command_cheker(*commands);
	ft_lstclear(&copy_stack);
}

int	main(int argc, char **argv)
{
	int		num;
	t_stack	*stack;
	t_stack	*commands;

	stack = NULL;
	commands = NULL;
	if (argc < 2)
		return (exit_error(&stack));
	while (--argc)
	{
		if (!check_arg(argv[argc], stack, &num))
			return (exit_error(&stack));
		else
			ft_lstadd_front(&stack, ft_lstnew(num));
	}
	if (ft_is_sort(stack, NULL))
		return (exit_error(&stack));
	find_solve(&commands, stack);
	print_commands(commands);
	ft_lstclear(&stack);
	ft_lstclear(&commands);
	return (0);
}
